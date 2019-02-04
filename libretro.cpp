#include	<stdarg.h>
#include "mednafen/mednafen.h"
#include "mednafen/mednafen-endian.h"
#include "mednafen/mempatcher.h"
#include "mednafen/git.h"
#include "mednafen/general.h"
#include "mednafen/md5.h"
#ifdef NEED_DEINTERLACER
#include	"mednafen/video/Deinterlacer.h"
#endif
#include "libretro.h"

static MDFNGI *game;

struct retro_perf_callback perf_cb;
retro_get_cpu_features_t perf_get_cpu_features_cb = NULL;
retro_log_printf_t log_cb;
static retro_video_refresh_t video_cb;
static retro_audio_sample_t audio_cb;
static retro_audio_sample_batch_t audio_batch_cb;
static retro_environment_t environ_cb;
static retro_input_poll_t input_poll_cb;
static retro_input_state_t input_state_cb;

static bool overscan;
static double last_sound_rate;
static MDFN_PixelFormat last_pixel_format;

static unsigned rot_screen;
static unsigned select_pressed_last_frame;

static MDFN_Surface *surf;

static bool failed_init;

static void hookup_ports(bool force);

static bool initial_ports_hookup = false;

std::string retro_base_directory;
std::string retro_base_name;
std::string retro_save_directory;

static void set_basename(const char *path)
{
   const char *base = strrchr(path, '/');
   if (!base)
      base = strrchr(path, '\\');

   if (base)
      retro_base_name = base + 1;
   else
      retro_base_name = path;

   retro_base_name = retro_base_name.substr(0, retro_base_name.find_last_of('.'));
}

//
// Copyright (c) 2004 K. Wilkins
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

//////////////////////////////////////////////////////////////////////////////
//                       Handy - An Atari Lynx Emulator                     //
//                          Copyright (c) 1996,1997                         //
//                                 K. Wilkins                               //
//////////////////////////////////////////////////////////////////////////////
// System object class                                                      //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// This class provides the glue to bind of of the emulation objects         //
// together via peek/poke handlers and pass thru interfaces to lower        //
// objects, all control of the emulator is done via this class. Update()    //
// does most of the work and each call emulates one CPU instruction and     //
// updates all of the relevant hardware if required. It must be remembered  //
// that if that instruction involves setting SPRGO then, it will cause a    //
// sprite painting operation and then a corresponding update of all of the  //
// hardware which will usually involve recursive calls to Update, see       //
// Mikey SPRGO code for more details.                                       //
//                                                                          //
//    K. Wilkins                                                            //
// August 1997                                                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
// Revision History:                                                        //
// -----------------                                                        //
//                                                                          //
// 01Aug1997 KW Document header added & class documented.                   //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#define SYSTEM_CPP

//#include <crtdbg.h>
//#define	TRACE_SYSTEM

#include "mednafen/lynx/system.h"

#include "mednafen/general.h"
#include "mednafen/mempatcher.h"

CSystem::CSystem(const uint8 *filememory, int32 filesize)
	:mCart(NULL),
	mRom(NULL),
	mMemMap(NULL),
	mRam(NULL),
	mCpu(NULL),
	mMikie(NULL),
	mSusie(NULL)
{
	mFileType=HANDY_FILETYPE_ILLEGAL;

	if(filesize < 11)
   {
      /* Lynx ROM image is too short. */
   }

	char clip[11];
	memcpy(clip,filememory,11);
	clip[4]=0;
	clip[10]=0;

	if(!strcmp(&clip[6],"BS93")) mFileType=HANDY_FILETYPE_HOMEBREW;
	else if(!strcmp(&clip[0],"LYNX")) mFileType=HANDY_FILETYPE_LNX;
	else if(filesize==128*1024 || filesize==256*1024 || filesize==512*1024)
	{
		/* Invalid Cart (type). but 128/256/512k size -> set to RAW and try to load raw rom image */
		mFileType=HANDY_FILETYPE_RAW;
	}
	else
	{
      /* File format is unknown to module. This will then
       * just load the core into an "Insert Game" screen */
	}

	MDFNMP_Init(65536, 1);

	// Create the system objects that we'll use

	// Attempt to load the cartridge errors caught above here...

	mRom = new CRom(MDFN_MakeFName(MDFNMKF_FIRMWARE, 0, "lynxboot.img").c_str());

	// An exception from this will be caught by the level above

	switch(mFileType)
	{
		case HANDY_FILETYPE_RAW:
		case HANDY_FILETYPE_LNX:
			mCart = new CCart(filememory,filesize);
			mRam = new CRam(0,0);
			break;
		case HANDY_FILETYPE_HOMEBREW:
			{
			 #if 0
			 static uint8 dummy_cart[CCart::HEADER_RAW_SIZE + 65536] = 
			 {
				'L', 'Y', 'N', 'X', 0x00, 0x01, 0x00, 0x00,
				0x01, 0x00,
			 };
			 mCart = new CCart(dummy_cart, sizeof(dummy_cart));
			 #else
			 mCart = new CCart(NULL, 0);
			 #endif
			 mRam = new CRam(filememory,filesize);
			}
			break;
		case HANDY_FILETYPE_SNAPSHOT:
		case HANDY_FILETYPE_ILLEGAL:
		default:
			mCart = new CCart(0,0);
			mRam = new CRam(0,0);
			break;
	}

	// These can generate exceptions

	mMikie = new CMikie(*this);
	mSusie = new CSusie(*this);

// Instantiate the memory map handler

	mMemMap = new CMemMap(*this);

// Now the handlers are set we can instantiate the CPU as is will use handlers on reset

	mCpu = new C65C02(*this);

// Now init is complete do a reset, this will cause many things to be reset twice
// but what the hell, who cares, I don't.....

	Reset();
}

CSystem::~CSystem()
{
	// Cleanup all our objects

	if(mCart!=NULL) delete mCart;
	if(mRom!=NULL) delete mRom;
	if(mRam!=NULL) delete mRam;
	if(mCpu!=NULL) delete mCpu;
	if(mMikie!=NULL) delete mMikie;
	if(mSusie!=NULL) delete mSusie;
	if(mMemMap!=NULL) delete mMemMap;
}

void CSystem::Reset(void)
{
	gSystemCycleCount=0;
	gNextTimerEvent=0;
	gCPUBootAddress=0;
	gSystemIRQ=FALSE;
	gSystemNMI=FALSE;
	gSystemCPUSleep=FALSE;
	gSystemHalt=FALSE;
	gSuzieDoneTime = 0;

	mMemMap->Reset();
	mCart->Reset();
	mRom->Reset();
	mRam->Reset();
	mMikie->Reset();
	mSusie->Reset();
	mCpu->Reset();

	// Homebrew hashup

	if(mFileType==HANDY_FILETYPE_HOMEBREW)
	{
		mMikie->PresetForHomebrew();

		C6502_REGS regs;
		mCpu->GetRegs(regs);
		regs.PC=(uint16)gCPUBootAddress;
		mCpu->SetRegs(regs);
	}
}

// Somewhat of a hack to make sure undrawn lines are black.
bool LynxLineDrawn[256];

static CSystem *lynxie = NULL;
extern MDFNGI EmulatedLynx;

static bool TestMagic(const char *name, MDFNFILE *fp)
{
 uint8 data[std::max<unsigned>(CCart::HEADER_RAW_SIZE, CRam::HEADER_RAW_SIZE)];
 uint64 rc;

 rc = fp->size;

 if(rc >= CCart::HEADER_RAW_SIZE && CCart::TestMagic(data, sizeof(data)))
  return true;

 if(rc >= CRam::HEADER_RAW_SIZE && CRam::TestMagic(data, sizeof(data)))
  return true;

 return false;
}

static int Load(const uint8_t *data, size_t size)
{
 lynxie = new CSystem(data, size);

 switch(lynxie->CartGetRotate())
 {
  case CART_ROTATE_LEFT:
   MDFNGameInfo->rotated = MDFN_ROTATE270;
   break;

  case CART_ROTATE_RIGHT:
   MDFNGameInfo->rotated = MDFN_ROTATE90;
   break;
 }

 if(lynxie->mRam->InfoRAMSize)
 {
  memcpy(MDFNGameInfo->MD5, lynxie->mRam->MD5, 16);
  MDFN_printf(_("RAM:       %u bytes\n"), lynxie->mRam->InfoRAMSize);
  MDFN_printf(_("CRC32:     0x%08x\n"), lynxie->mRam->CRC32());
  MDFN_printf(_("RAM MD5:   0x%s\n"), md5_context::asciistr(MDFNGameInfo->MD5, 0).c_str());
 }
 else
 {
  memcpy(MDFNGameInfo->MD5, lynxie->mCart->MD5, 16);
  MDFN_printf(_("ROM:       %dKiB\n"), (lynxie->mCart->InfoROMSize + 1023) / 1024);
  MDFN_printf(_("CRC32:     0x%08x\n"), lynxie->mCart->CRC32());
  MDFN_printf(_("ROM MD5:   0x%s\n"), md5_context::asciistr(MDFNGameInfo->MD5, 0).c_str());
 }

 MDFNGameInfo->fps = (uint32)(59.8 * 65536 * 256);

 if(MDFN_GetSettingB("lynx.lowpass"))
 {
  lynxie->mMikie->miksynth.treble_eq(-35);
 }
 else
 {
  lynxie->mMikie->miksynth.treble_eq(0);
 }
 return(1);
}

static void CloseGame(void)
{
 if(lynxie)
 {
  delete lynxie;
  lynxie = NULL;
 }
}

static uint8 *chee;
static void Emulate(EmulateSpecStruct *espec)
{
 espec->DisplayRect.x = 0;
 espec->DisplayRect.y = 0;
 espec->DisplayRect.w = 160;
 espec->DisplayRect.h = 102;

 if(espec->VideoFormatChanged)
  lynxie->DisplaySetAttributes(espec->surface->format); // FIXME, pitch

 if(espec->SoundFormatChanged)
 {
  lynxie->mMikie->mikbuf.set_sample_rate(espec->SoundRate ? espec->SoundRate : 44100, 60);
  lynxie->mMikie->mikbuf.clock_rate((long int)(16000000 / 4));
  lynxie->mMikie->mikbuf.bass_freq(60);
  lynxie->mMikie->miksynth.volume(0.50);
 }

 uint16 butt_data = chee[0] | (chee[1] << 8);

 lynxie->SetButtonData(butt_data);

 MDFNMP_ApplyPeriodicCheats();

 memset(LynxLineDrawn, 0, sizeof(LynxLineDrawn[0]) * 102);

 lynxie->mMikie->mpSkipFrame = espec->skip;
 lynxie->mMikie->mpDisplayCurrent = espec->surface;
 lynxie->mMikie->mpDisplayCurrentLine = 0;
 lynxie->mMikie->startTS = gSystemCycleCount;

 while(lynxie->mMikie->mpDisplayCurrent && (gSystemCycleCount - lynxie->mMikie->startTS) < 700000)
 {
  lynxie->Update();
//  printf("%d ", gSystemCycleCount - lynxie->mMikie->startTS);
 }

 {
  // FIXME, we should integrate this into mikie.*
  uint32 color_black = espec->surface->MakeColor(30, 30, 30);

  for(int y = 0; y < 102; y++)
  {
   if(espec->surface->format.bpp == 16)
   {
    uint16 *row = espec->surface->pixels16 + y * espec->surface->pitchinpix;

    if(!LynxLineDrawn[y])
    {
     for(int x = 0; x < 160; x++)
      row[x] = color_black;
    }
   }
   else
   {
    uint32 *row = espec->surface->pixels + y * espec->surface->pitchinpix;

    if(!LynxLineDrawn[y])
    {
     for(int x = 0; x < 160; x++)
      row[x] = color_black;
    }
   }
  }
 }

 espec->MasterCycles = gSystemCycleCount - lynxie->mMikie->startTS;

 if(espec->SoundBuf)
 {
  lynxie->mMikie->mikbuf.end_frame((gSystemCycleCount - lynxie->mMikie->startTS) >> 2);
  espec->SoundBufSize = lynxie->mMikie->mikbuf.read_samples(espec->SoundBuf, espec->SoundBufMaxSize) / 2; // divide by nr audio chn
 }
 else
  espec->SoundBufSize = 0;
}

static void SetInput(int port, const char *type, void *ptr)
{
 chee = (uint8 *)ptr;
}

static void TransformInput(void)
{
 if(MDFN_GetSettingB("lynx.rotateinput"))
 {
  static const unsigned bp[4] = { 4, 6, 5, 7 };
  const unsigned offs = MDFNGameInfo->rotated;
  uint16 butt_data = MDFN_de16lsb(chee);

  butt_data = (butt_data & 0xFF0F) |
	      (((butt_data >> bp[0]) & 1) << bp[(0 + offs) & 3]) |
	      (((butt_data >> bp[1]) & 1) << bp[(1 + offs) & 3]) |
	      (((butt_data >> bp[2]) & 1) << bp[(2 + offs) & 3]) |
	      (((butt_data >> bp[3]) & 1) << bp[(3 + offs) & 3]);
  //printf("%d, %04x\n", MDFNGameInfo->rotated, butt_data);
  MDFN_en16lsb(chee, butt_data);
 }
}

int StateAction(StateMem *sm, int load, int data_only)
{
 SFORMAT SystemRegs[] =
 {
	SFVAR(gSuzieDoneTime),
        SFVAR(gSystemCycleCount),
        SFVAR(gNextTimerEvent),
        SFVAR(gCPUBootAddress),
        SFVAR(gSystemIRQ),
        SFVAR(gSystemNMI),
        SFVAR(gSystemCPUSleep),
        SFVAR(gSystemHalt),
	SFARRAYN(lynxie->GetRamPointer(), RAM_SIZE, "RAM"),
	SFEND
 };

 MDFNSS_StateAction(sm, load, data_only, SystemRegs, "SYST", false);

 if(!lynxie->mSusie->StateAction(sm, load, data_only))
  return(0);
 if(!lynxie->mMemMap->StateAction(sm, load, data_only))
  return(0);

 if(!lynxie->mCart->StateAction(sm, load, data_only))
  return(0);

 if(!lynxie->mMikie->StateAction(sm, load, data_only))
  return(0);

 if(!lynxie->mCpu->StateAction(sm, load, data_only))
  return(0);

 return(1);
}

static void SetLayerEnableMask(uint64 mask)
{


}

static void DoSimpleCommand(int cmd)
{
 switch(cmd)
 {
  case MDFN_MSC_POWER:
  case MDFN_MSC_RESET: lynxie->Reset(); break;
 }
}

static MDFNSetting LynxSettings[] =
{
 { "lynx.rotateinput", MDFNSF_NOFLAGS,	"Virtually rotate D-pad along with screen.", NULL, MDFNST_BOOL, "1" },
 { "lynx.lowpass", MDFNSF_CAT_SOUND,	"Enable sound output lowpass filter.", NULL, MDFNST_BOOL, "1" },
 { NULL }
};

static const InputDeviceInputInfoStruct IDII[] =
{
 { "a", "A (outer)", 8, IDIT_BUTTON_CAN_RAPID, NULL },
 { "b", "B (inner)", 7, IDIT_BUTTON_CAN_RAPID, NULL },
 { "option_2", "Option 2 (lower)", 5, IDIT_BUTTON_CAN_RAPID, NULL },
 { "option_1", "Option 1 (upper)", 4, IDIT_BUTTON_CAN_RAPID, NULL },

 { "left", "LEFT ←", 	/*VIRTB_DPAD0_L,*/ 2, IDIT_BUTTON, "right",		{ "up", "right", "down" } },
 { "right", "RIGHT →", 	/*VIRTB_DPAD0_R,*/ 3, IDIT_BUTTON, "left", 		{ "down", "left", "up" } },
 { "up", "UP ↑", 	/*VIRTB_DPAD0_U,*/ 0, IDIT_BUTTON, "down",		{ "right", "down", "left" } },
 { "down", "DOWN ↓", 	/*VIRTB_DPAD0_D,*/ 1, IDIT_BUTTON, "up", 		{ "left", "up", "right" } },

 { "pause", "PAUSE", 6, IDIT_BUTTON, NULL },
};

static InputDeviceInfoStruct InputDeviceInfo[] =
{
 {
  "gamepad",
  "Gamepad",
  NULL,
  NULL,
  sizeof(IDII) / sizeof(InputDeviceInputInfoStruct),
  IDII,
 }
};

static const InputPortInfoStruct PortInfo[] =
{
 { "builtin", "Built-In", sizeof(InputDeviceInfo) / sizeof(InputDeviceInfoStruct), InputDeviceInfo, 0 }
};

static InputInfoStruct InputInfo =
{
 sizeof(PortInfo) / sizeof(InputPortInfoStruct),
 PortInfo
};

static const FileExtensionSpecStruct KnownExtensions[] =
{
 { ".lnx", "Atari Lynx ROM Image" },
 { NULL, NULL }
};

MDFNGI EmulatedLynx =
{
 LynxSettings,
 MDFN_MASTERCLOCK_FIXED(16000000),
 0,

 false, // Multires possible?

 160,   // lcm_width
 102,   // lcm_height
 NULL,  // Dummy


 160,	// Nominal width
 102,	// Nominal height

 160,	// Framebuffer width
 102,	// Framebuffer height

 2,     // Number of output sound channels
};


#ifdef NEED_DEINTERLACER
static bool PrevInterlaced;
static Deinterlacer deint;
#endif

#define MEDNAFEN_CORE_NAME_MODULE "lynx"
#define MEDNAFEN_CORE_NAME "Beetle Lynx"
#define MEDNAFEN_CORE_VERSION "v0.9.47"
#define MEDNAFEN_CORE_EXTENSIONS "lnx"
#define MEDNAFEN_CORE_TIMING_FPS 75.0
#define MEDNAFEN_CORE_GEOMETRY_BASE_W 160
#define MEDNAFEN_CORE_GEOMETRY_BASE_H 102
#define MEDNAFEN_CORE_GEOMETRY_MAX_W 160
#define MEDNAFEN_CORE_GEOMETRY_MAX_H 102
#define MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO (80.0 / 51.0)
#define FB_WIDTH 160
#define FB_HEIGHT 102

#define FB_MAX_HEIGHT FB_HEIGHT

const char *mednafen_core_str = MEDNAFEN_CORE_NAME;

static void check_system_specs(void)
{
   unsigned level = 0;
   environ_cb(RETRO_ENVIRONMENT_SET_PERFORMANCE_LEVEL, &level);
}

void retro_init(void)
{
   struct retro_log_callback log;
   if (environ_cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &log))
      log_cb = log.log;
   else 
      log_cb = NULL;

   MDFNI_InitializeModule();

   const char *dir = NULL;

   if (environ_cb(RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY, &dir) && dir)
   {
      retro_base_directory = dir;
      // Make sure that we don't have any lingering slashes, etc, as they break Windows.
      size_t last = retro_base_directory.find_last_not_of("/\\");
      if (last != std::string::npos)
         last++;

      retro_base_directory = retro_base_directory.substr(0, last);

      MDFNI_Initialize(retro_base_directory.c_str());
   }
   else
   {
      /* TODO: Add proper fallback */
      if (log_cb)
         log_cb(RETRO_LOG_WARN, "System directory is not defined. Fallback on using same dir as ROM for system directory later ...\n");
      failed_init = true;
   }
   
   if (environ_cb(RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY, &dir) && dir)
   {
	  // If save directory is defined use it, otherwise use system directory
      //retro_save_directory = *dir ? dir : retro_base_directory;
	  retro_save_directory = dir;
      // Make sure that we don't have any lingering slashes, etc, as they break Windows.
      size_t last = retro_save_directory.find_last_not_of("/\\");
      if (last != std::string::npos)
         last++;

      retro_save_directory = retro_save_directory.substr(0, last);      
   }
   else
   {
      /* TODO: Add proper fallback */
      if (log_cb)
         log_cb(RETRO_LOG_WARN, "Save directory is not defined. Fallback on using SYSTEM directory ...\n");
	  retro_save_directory = retro_base_directory;
   }      

#if defined(WANT_16BPP) && defined(FRONTEND_SUPPORTS_RGB565)
   enum retro_pixel_format rgb565 = RETRO_PIXEL_FORMAT_RGB565;
   if (environ_cb(RETRO_ENVIRONMENT_SET_PIXEL_FORMAT, &rgb565) && log_cb)
      log_cb(RETRO_LOG_INFO, "Frontend supports RGB565 - will use that instead of XRGB1555.\n");
#endif

   if (environ_cb(RETRO_ENVIRONMENT_GET_PERF_INTERFACE, &perf_cb))
      perf_get_cpu_features_cb = perf_cb.get_cpu_features;
   else
      perf_get_cpu_features_cb = NULL;

   check_system_specs();
}

void retro_reset(void)
{
   DoSimpleCommand(MDFN_MSC_RESET);
}

bool retro_load_game_special(unsigned, const struct retro_game_info *, size_t)
{
   return false;
}

static void set_volume (uint32_t *ptr, unsigned number)
{
   switch(number)
   {
      default:
         *ptr = number;
         break;
   }
}

static void check_variables(void)
{
   struct retro_variable var = {0};
}

#define MAX_PLAYERS 1
#define MAX_BUTTONS 9
static uint8_t input_buf[MAX_PLAYERS][2] = {{0}};


static void hookup_ports(bool force)
{
   if (initial_ports_hookup && !force)
      return;

   SetInput(0, "gamepad", &input_buf);

   initial_ports_hookup = true;
}

static MDFNGI *MDFNI_LoadGame(const uint8_t *, size_t);
bool retro_load_game(const struct retro_game_info *info)
{
   if (!info || failed_init)
      return false;

#ifdef WANT_32BPP
   enum retro_pixel_format fmt = RETRO_PIXEL_FORMAT_XRGB8888;
   if (!environ_cb(RETRO_ENVIRONMENT_SET_PIXEL_FORMAT, &fmt))
   {
      if (log_cb)
         log_cb(RETRO_LOG_ERROR, "Pixel format XRGB8888 not supported by platform, cannot use %s.\n", MEDNAFEN_CORE_NAME);
      return false;
   }
#endif

   overscan = false;
   environ_cb(RETRO_ENVIRONMENT_GET_OVERSCAN, &overscan);

   game = MDFNI_LoadGame((const uint8_t *)info->data, info->size);

   if (!game)
      return false;

   MDFN_PixelFormat pix_fmt(MDFN_COLORSPACE_RGB, 16, 8, 0, 24);
   memset(&last_pixel_format, 0, sizeof(MDFN_PixelFormat));
   
   surf = new MDFN_Surface(NULL, FB_WIDTH, FB_HEIGHT, FB_WIDTH, pix_fmt);

#ifdef NEED_DEINTERLACER
	PrevInterlaced = false;
	deint.ClearState();
#endif

   hookup_ports(true);

   rot_screen = 0;
   select_pressed_last_frame = 0;

   check_variables();

   return game;
}

void retro_unload_game()
{
   if (!game)
      return;

   MDFNI_CloseGame();
}

// Hardcoded for PSX. No reason to parse lots of structures ...
// See mednafen/psx/input/gamepad.cpp
static void update_input(void)
{
   static unsigned map[4][9] = {
      {
         RETRO_DEVICE_ID_JOYPAD_A,
         RETRO_DEVICE_ID_JOYPAD_B,
         RETRO_DEVICE_ID_JOYPAD_L,
         RETRO_DEVICE_ID_JOYPAD_R,
         RETRO_DEVICE_ID_JOYPAD_LEFT,
         RETRO_DEVICE_ID_JOYPAD_RIGHT,
         RETRO_DEVICE_ID_JOYPAD_UP,
         RETRO_DEVICE_ID_JOYPAD_DOWN,
         RETRO_DEVICE_ID_JOYPAD_START
      },
      {
         RETRO_DEVICE_ID_JOYPAD_A,
         RETRO_DEVICE_ID_JOYPAD_B,
         RETRO_DEVICE_ID_JOYPAD_L,
         RETRO_DEVICE_ID_JOYPAD_R,
         RETRO_DEVICE_ID_JOYPAD_DOWN,
         RETRO_DEVICE_ID_JOYPAD_UP,
         RETRO_DEVICE_ID_JOYPAD_LEFT,
         RETRO_DEVICE_ID_JOYPAD_RIGHT,
         RETRO_DEVICE_ID_JOYPAD_START
      },
      {
         RETRO_DEVICE_ID_JOYPAD_A,
         RETRO_DEVICE_ID_JOYPAD_B,
         RETRO_DEVICE_ID_JOYPAD_L,
         RETRO_DEVICE_ID_JOYPAD_R,
         RETRO_DEVICE_ID_JOYPAD_RIGHT,
         RETRO_DEVICE_ID_JOYPAD_LEFT,
         RETRO_DEVICE_ID_JOYPAD_DOWN,
         RETRO_DEVICE_ID_JOYPAD_UP,
         RETRO_DEVICE_ID_JOYPAD_START
      },
      {
         RETRO_DEVICE_ID_JOYPAD_A,
         RETRO_DEVICE_ID_JOYPAD_B,
         RETRO_DEVICE_ID_JOYPAD_L,
         RETRO_DEVICE_ID_JOYPAD_R,
         RETRO_DEVICE_ID_JOYPAD_UP,
         RETRO_DEVICE_ID_JOYPAD_DOWN,
         RETRO_DEVICE_ID_JOYPAD_RIGHT,
         RETRO_DEVICE_ID_JOYPAD_LEFT,
         RETRO_DEVICE_ID_JOYPAD_START
      },
   };

   for (unsigned j = 0; j < MAX_PLAYERS; j++)
   {
      uint16_t input_state = 0;
      for (unsigned i = 0; i < MAX_BUTTONS; i++)
         input_state |= input_state_cb(j, RETRO_DEVICE_JOYPAD, 0, map[rot_screen][i]) ? (1 << i) : 0;

      // Input data must be little endian.
      input_buf[j][0] = (input_state >> 0) & 0xff;
      input_buf[j][1] = (input_state >> 8) & 0xff;
   }

   unsigned select_button = input_state_cb(0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_SELECT);

   if (select_button && !select_pressed_last_frame)
   {
      rot_screen++;
      if (rot_screen > 3)
         rot_screen = 0;

      const float aspect[2] = { (80.0 / 51.0), (51.0 / 80.0) };
      const unsigned rot_angle[4] = { 0, 1, 2, 3 };
      struct retro_game_geometry new_geom = { FB_WIDTH, FB_HEIGHT, FB_WIDTH, FB_HEIGHT, aspect[rot_screen & 1] };
      environ_cb(RETRO_ENVIRONMENT_SET_GEOMETRY, (void*)&new_geom);
      environ_cb(RETRO_ENVIRONMENT_SET_ROTATION, (void*)&rot_angle[rot_screen]);
   }

   select_pressed_last_frame = select_button;
}

static uint64_t video_frames, audio_frames;


void retro_run()
{
   input_poll_cb();

   update_input();

   static int16_t sound_buf[0x10000];
   static MDFN_Rect rects[FB_MAX_HEIGHT];
   rects[0].w = ~0;

   EmulateSpecStruct spec = {0};
   spec.surface = surf;
   spec.SoundRate = 44100;
   spec.SoundBuf = sound_buf;
   spec.LineWidths = rects;
   spec.SoundBufMaxSize = sizeof(sound_buf) / 2;
   spec.SoundVolume = 1.0;
   spec.soundmultiplier = 1.0;
   spec.SoundBufSize = 0;
   spec.VideoFormatChanged = false;
   spec.SoundFormatChanged = false;

   if (memcmp(&last_pixel_format, &spec.surface->format, sizeof(MDFN_PixelFormat)))
   {
      spec.VideoFormatChanged = TRUE;

      last_pixel_format = spec.surface->format;
   }

   if (spec.SoundRate != last_sound_rate)
   {
      spec.SoundFormatChanged = true;
      last_sound_rate = spec.SoundRate;
   }

   Emulate(&spec);

#ifdef NEED_DEINTERLACER
   if (spec.InterlaceOn)
   {
      if (!PrevInterlaced)
         deint.ClearState();

      deint.Process(spec.surface, spec.DisplayRect, spec.LineWidths, spec.InterlaceField);

      PrevInterlaced = true;

      spec.InterlaceOn = false;
      spec.InterlaceField = 0;
   }
   else
      PrevInterlaced = false;
#endif

   int16 *const SoundBuf = spec.SoundBuf + spec.SoundBufSizeALMS * 2;
   int32 SoundBufSize = spec.SoundBufSize - spec.SoundBufSizeALMS;
   const int32 SoundBufMaxSize = spec.SoundBufMaxSize - spec.SoundBufSizeALMS;

   spec.SoundBufSize = spec.SoundBufSizeALMS + SoundBufSize;

   unsigned width  = spec.DisplayRect.w;
   unsigned height = spec.DisplayRect.h;

#if defined(WANT_32BPP)
   const uint32_t *pix = surf->pixels;
   video_cb(pix, width, height, FB_WIDTH << 2);
#elif defined(WANT_16BPP)
   const uint16_t *pix = surf->pixels16;
   video_cb(pix, width, height, FB_WIDTH << 1);
#endif

   video_frames++;
   audio_frames += spec.SoundBufSize;

   audio_batch_cb(spec.SoundBuf, spec.SoundBufSize);

   bool updated = false;
   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE, &updated) && updated)
      check_variables();
}

void retro_get_system_info(struct retro_system_info *info)
{
   memset(info, 0, sizeof(*info));
   info->library_name     = MEDNAFEN_CORE_NAME;
#ifndef GIT_VERSION
#define GIT_VERSION ""
#endif
   info->library_version  = MEDNAFEN_CORE_VERSION GIT_VERSION;
   info->need_fullpath    = false;
   info->valid_extensions = MEDNAFEN_CORE_EXTENSIONS;
   info->block_extract    = false;
}

void retro_get_system_av_info(struct retro_system_av_info *info)
{
   memset(info, 0, sizeof(*info));
   info->timing.fps            = MEDNAFEN_CORE_TIMING_FPS;
   info->timing.sample_rate    = 44100.0;
   info->geometry.base_width   = MEDNAFEN_CORE_GEOMETRY_BASE_W;
   info->geometry.base_height  = MEDNAFEN_CORE_GEOMETRY_BASE_H;
   info->geometry.max_width    = MEDNAFEN_CORE_GEOMETRY_MAX_W;
   info->geometry.max_height   = MEDNAFEN_CORE_GEOMETRY_MAX_H;
   info->geometry.aspect_ratio = MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO;
}

void retro_deinit()
{
   delete surf;
   surf = NULL;

   if (log_cb)
   {
      log_cb(RETRO_LOG_INFO, "[%s]: Samples / Frame: %.5f\n",
            mednafen_core_str, (double)audio_frames / video_frames);
      log_cb(RETRO_LOG_INFO, "[%s]: Estimated FPS: %.5f\n",
            mednafen_core_str, (double)video_frames * 44100 / audio_frames);
   }
}

unsigned retro_get_region(void)
{
   return RETRO_REGION_NTSC; // FIXME: Regions for other cores.
}

unsigned retro_api_version(void)
{
   return RETRO_API_VERSION;
}

void retro_set_controller_port_device(unsigned in_port, unsigned device)
{
}

void retro_set_environment(retro_environment_t cb)
{
   environ_cb = cb;

}

void retro_set_audio_sample(retro_audio_sample_t cb)
{
   audio_cb = cb;
}

void retro_set_audio_sample_batch(retro_audio_sample_batch_t cb)
{
   audio_batch_cb = cb;
}

void retro_set_input_poll(retro_input_poll_t cb)
{
   input_poll_cb = cb;
}

void retro_set_input_state(retro_input_state_t cb)
{
   input_state_cb = cb;
}

void retro_set_video_refresh(retro_video_refresh_t cb)
{
   video_cb = cb;
}

static size_t serialize_size;

size_t retro_serialize_size(void)
{
   StateMem st;

   st.data           = NULL;
   st.loc            = 0;
   st.len            = 0;
   st.malloced       = 0;
   st.initial_malloc = 0;

   if (!MDFNSS_SaveSM(&st, 0, 0, NULL, NULL, NULL))
      return 0;

   free(st.data);

   return serialize_size = st.len;
}

bool retro_serialize(void *data, size_t size)
{
   StateMem st;
   bool ret          = false;
   uint8_t *_dat     = (uint8_t*)malloc(size);

   if (!_dat)
      return false;

   /* Mednafen can realloc the buffer so we need to ensure this is safe. */
   st.data           = _dat;
   st.loc            = 0;
   st.len            = 0;
   st.malloced       = size;
   st.initial_malloc = 0;

   ret = MDFNSS_SaveSM(&st, 0, 0, NULL, NULL, NULL);

   memcpy(data, st.data, size);
   free(st.data);

   return ret;
}

bool retro_unserialize(const void *data, size_t size)
{
   StateMem st;
   memset(&st, 0, sizeof(st));
   st.data = (uint8_t*)data;
   st.len  = size;

   return MDFNSS_LoadSM(&st, 0, 0);
}

void *retro_get_memory_data(unsigned type)
{
   if (lynxie && type == RETRO_MEMORY_SYSTEM_RAM)
      return lynxie->GetRamPointer();
   return NULL;
}

size_t retro_get_memory_size(unsigned type)
{
   if (type == RETRO_MEMORY_SYSTEM_RAM)
      return 1024 * 64;
   return 0;
}

void retro_cheat_reset(void)
{}

void retro_cheat_set(unsigned, bool, const char *)
{}

#ifdef _WIN32
static void sanitize_path(std::string &path)
{
   size_t size = path.size();
   for (size_t i = 0; i < size; i++)
      if (path[i] == '/')
         path[i] = '\\';
}
#endif

// Use a simpler approach to make sure that things go right for libretro.
std::string MDFN_MakeFName(MakeFName_Type type, int id1, const char *cd1)
{
   char slash;
#ifdef _WIN32
   slash = '\\';
#else
   slash = '/';
#endif
   std::string ret;
   switch (type)
   {
      case MDFNMKF_SAV:
         ret = retro_save_directory +slash + retro_base_name +
            std::string(".") + std::string(cd1);
         break;
      case MDFNMKF_FIRMWARE:
         ret = retro_base_directory + slash + std::string(cd1);
#ifdef _WIN32
   sanitize_path(ret); // Because Windows path handling is mongoloid.
#endif
         break;
      default:	  
         break;
   }

   if (log_cb)
      log_cb(RETRO_LOG_INFO, "MDFN_MakeFName: %s\n", ret.c_str());
   return ret;
}

void MDFND_DispMessage(unsigned char *str)
{
   if (log_cb)
      log_cb(RETRO_LOG_INFO, "%s", str);
}

void MDFND_Message(const char *str)
{
   if (log_cb)
      log_cb(RETRO_LOG_INFO, "%s", str);
}

void MDFND_MidSync(const EmulateSpecStruct *)
{}

void MDFN_MidLineUpdate(EmulateSpecStruct *espec, int y)
{
 //MDFND_MidLineUpdate(espec, y);
}

void MDFND_PrintError(const char* err)
{
   if (log_cb)
      log_cb(RETRO_LOG_ERROR, "%s\n", err);
}

extern MDFNGI EmulatedLynx;
MDFNGI *MDFNGameInfo = &EmulatedLynx;

/* forward declarations */
extern void MDFND_DispMessage(unsigned char *str);

void MDFN_DispMessage(const char *format, ...)
{
 va_list ap;
 va_start(ap,format);
 char *msg = new char[4096];

 vsnprintf(msg, 4096, format,ap);
 va_end(ap);

 MDFND_DispMessage((UTF8*)msg);
}

void MDFN_ResetMessages(void)
{
 MDFND_DispMessage(NULL);
}

static MDFNGI *MDFNI_LoadGame(const uint8_t *data, size_t size)
{
	if (!data || !size) {
		MDFN_indent(2);
		goto error;
	}

	MDFNGameInfo = &EmulatedLynx;

	MDFN_indent(1);

	MDFN_printf(_("Using module: lynx\n\n"));
	MDFN_indent(1);

	//
	// Load per-game settings
	//
	// Maybe we should make a "pgcfg" subdir, and automatically load all files in it?
	// End load per-game settings
	//

	if(Load(data, size) <= 0)
		goto error;

	MDFN_LoadGameCheats(NULL);
	MDFNMP_InstallReadPatches();

	MDFN_ResetMessages();	// Save state, status messages, etc.

	MDFN_indent(-2);

   return(MDFNGameInfo);

error:
   MDFN_indent(-2);
   MDFNGameInfo = NULL;
   return NULL;
}

void MDFNI_CloseGame(void)
{
   if(!MDFNGameInfo)
      return;

   MDFN_FlushGameCheats(0);

   CloseGame();

   MDFNMP_Kill();

   MDFNGameInfo = NULL;
}

bool MDFNI_InitializeModule(void)
{

 return(1);
}

int MDFNI_Initialize(const char *basedir)
{
	return(1);
}

static int curindent = 0;

void MDFN_indent(int indent)
{
 curindent += indent;
}

static uint8 lastchar = 0;

void MDFN_printf(const char *format, ...)
{
   char *format_temp;
   char *temp;
   unsigned int x, newlen;

   va_list ap;
   va_start(ap,format);


   // First, determine how large our format_temp buffer needs to be.
   uint8 lastchar_backup = lastchar; // Save lastchar!
   for(newlen=x=0;x<strlen(format);x++)
   {
      if(lastchar == '\n' && format[x] != '\n')
      {
         int y;
         for(y=0;y<curindent;y++)
            newlen++;
      }
      newlen++;
      lastchar = format[x];
   }

   format_temp = (char *)malloc(newlen + 1); // Length + NULL character, duh

   // Now, construct our format_temp string
   lastchar = lastchar_backup; // Restore lastchar
   for(newlen=x=0;x<strlen(format);x++)
   {
      if(lastchar == '\n' && format[x] != '\n')
      {
         int y;
         for(y=0;y<curindent;y++)
            format_temp[newlen++] = ' ';
      }
      format_temp[newlen++] = format[x];
      lastchar = format[x];
   }

   format_temp[newlen] = 0;

   temp = new char[4096];
   vsnprintf(temp, 4096, format_temp, ap);
   free(format_temp);

   MDFND_Message(temp);
   delete[] temp;

   va_end(ap);
}

void MDFN_PrintError(const char *format, ...)
{
 char *temp;

 va_list ap;

 va_start(ap, format);

 temp = new char[4096];
 vsnprintf(temp, 4096, format, ap);
 MDFND_PrintError(temp);
 delete[] temp;

 va_end(ap);
}

void MDFN_DebugPrintReal(const char *file, const int line, const char *format, ...)
{
 char *temp;

 va_list ap;

 va_start(ap, format);

 temp = new char[4096];
 vsnprintf(temp, 4096, format, ap);
 fprintf(stderr, "%s:%d  %s\n", file, line, temp);
 delete[] temp;

 va_end(ap);
}
