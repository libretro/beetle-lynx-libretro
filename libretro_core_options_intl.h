#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/
/* RETRO_LANGUAGE_AR */

#define LYNX_ROT_SCREEN_LABEL_AR NULL
#define LYNX_ROT_SCREEN_INFO_0_AR NULL
#define OPTION_VAL_AUTO_AR NULL
#define OPTION_VAL_MANUAL_AR NULL
#define LYNX_PIX_FORMAT_LABEL_AR NULL
#define OPTION_VAL_16_AR NULL
#define OPTION_VAL_32_AR NULL

struct retro_core_option_v2_category option_cats_ar[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ar[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_AR,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_AR,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_AR },
         { "manual", OPTION_VAL_MANUAL_AR },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_AR,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_AR },
         { "32", OPTION_VAL_32_AR },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ar = {
   option_cats_ar,
   option_defs_ar
};

/* RETRO_LANGUAGE_AST */

#define LYNX_ROT_SCREEN_LABEL_AST NULL
#define LYNX_ROT_SCREEN_INFO_0_AST NULL
#define OPTION_VAL_AUTO_AST NULL
#define OPTION_VAL_MANUAL_AST NULL
#define LYNX_PIX_FORMAT_LABEL_AST NULL
#define OPTION_VAL_16_AST NULL
#define OPTION_VAL_32_AST NULL

struct retro_core_option_v2_category option_cats_ast[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ast[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_AST,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_AST,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_AST },
         { "manual", OPTION_VAL_MANUAL_AST },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_AST,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_AST },
         { "32", OPTION_VAL_32_AST },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ast = {
   option_cats_ast,
   option_defs_ast
};

/* RETRO_LANGUAGE_CA */

#define LYNX_ROT_SCREEN_LABEL_CA NULL
#define LYNX_ROT_SCREEN_INFO_0_CA NULL
#define OPTION_VAL_AUTO_CA NULL
#define OPTION_VAL_MANUAL_CA NULL
#define LYNX_PIX_FORMAT_LABEL_CA NULL
#define OPTION_VAL_16_CA NULL
#define OPTION_VAL_32_CA NULL

struct retro_core_option_v2_category option_cats_ca[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ca[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_CA,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_CA,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_CA },
         { "manual", OPTION_VAL_MANUAL_CA },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_CA,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_CA },
         { "32", OPTION_VAL_32_CA },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ca = {
   option_cats_ca,
   option_defs_ca
};

/* RETRO_LANGUAGE_CHS */

#define LYNX_ROT_SCREEN_LABEL_CHS NULL
#define LYNX_ROT_SCREEN_INFO_0_CHS NULL
#define OPTION_VAL_AUTO_CHS NULL
#define OPTION_VAL_MANUAL_CHS NULL
#define LYNX_PIX_FORMAT_LABEL_CHS NULL
#define OPTION_VAL_16_CHS NULL
#define OPTION_VAL_32_CHS NULL

struct retro_core_option_v2_category option_cats_chs[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_chs[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_CHS,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_CHS },
         { "manual", OPTION_VAL_MANUAL_CHS },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_CHS,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_CHS },
         { "32", OPTION_VAL_32_CHS },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_chs = {
   option_cats_chs,
   option_defs_chs
};

/* RETRO_LANGUAGE_CHT */

#define LYNX_ROT_SCREEN_LABEL_CHT NULL
#define LYNX_ROT_SCREEN_INFO_0_CHT NULL
#define OPTION_VAL_AUTO_CHT NULL
#define OPTION_VAL_MANUAL_CHT NULL
#define LYNX_PIX_FORMAT_LABEL_CHT NULL
#define OPTION_VAL_16_CHT NULL
#define OPTION_VAL_32_CHT NULL

struct retro_core_option_v2_category option_cats_cht[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cht[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_CHT,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_CHT },
         { "manual", OPTION_VAL_MANUAL_CHT },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_CHT,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_CHT },
         { "32", OPTION_VAL_32_CHT },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_cht = {
   option_cats_cht,
   option_defs_cht
};

/* RETRO_LANGUAGE_CS */

#define LYNX_ROT_SCREEN_LABEL_CS NULL
#define LYNX_ROT_SCREEN_INFO_0_CS NULL
#define OPTION_VAL_AUTO_CS NULL
#define OPTION_VAL_MANUAL_CS NULL
#define LYNX_PIX_FORMAT_LABEL_CS NULL
#define OPTION_VAL_16_CS NULL
#define OPTION_VAL_32_CS NULL

struct retro_core_option_v2_category option_cats_cs[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cs[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_CS,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_CS,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_CS },
         { "manual", OPTION_VAL_MANUAL_CS },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_CS,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_CS },
         { "32", OPTION_VAL_32_CS },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_cs = {
   option_cats_cs,
   option_defs_cs
};

/* RETRO_LANGUAGE_CY */

#define LYNX_ROT_SCREEN_LABEL_CY NULL
#define LYNX_ROT_SCREEN_INFO_0_CY NULL
#define OPTION_VAL_AUTO_CY NULL
#define OPTION_VAL_MANUAL_CY NULL
#define LYNX_PIX_FORMAT_LABEL_CY NULL
#define OPTION_VAL_16_CY NULL
#define OPTION_VAL_32_CY NULL

struct retro_core_option_v2_category option_cats_cy[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cy[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_CY,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_CY,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_CY },
         { "manual", OPTION_VAL_MANUAL_CY },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_CY,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_CY },
         { "32", OPTION_VAL_32_CY },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_cy = {
   option_cats_cy,
   option_defs_cy
};

/* RETRO_LANGUAGE_DA */

#define LYNX_ROT_SCREEN_LABEL_DA NULL
#define LYNX_ROT_SCREEN_INFO_0_DA NULL
#define OPTION_VAL_AUTO_DA NULL
#define OPTION_VAL_MANUAL_DA NULL
#define LYNX_PIX_FORMAT_LABEL_DA NULL
#define OPTION_VAL_16_DA NULL
#define OPTION_VAL_32_DA NULL

struct retro_core_option_v2_category option_cats_da[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_da[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_DA,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_DA,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_DA },
         { "manual", OPTION_VAL_MANUAL_DA },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_DA,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_DA },
         { "32", OPTION_VAL_32_DA },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_da = {
   option_cats_da,
   option_defs_da
};

/* RETRO_LANGUAGE_DE */

#define LYNX_ROT_SCREEN_LABEL_DE "Bildschirm automatisch drehen"
#define LYNX_ROT_SCREEN_INFO_0_DE "Bildschirmausrichtung und Tastenbelegung bei bekannten Spielen automatisch drehen. Bei \"Manuell\" wird die Bildschirmrotation durch Drücken der SELECT-Taste angepasst, andernfalls kann eine feste Drehung von 0, 90, 180 oder 270 Grad gegen den Uhrzeigersinn eingestellt werden."
#define OPTION_VAL_AUTO_DE NULL
#define OPTION_VAL_MANUAL_DE NULL
#define LYNX_PIX_FORMAT_LABEL_DE "Farbformat (Neustart erforderlich)"
#define OPTION_VAL_16_DE NULL
#define OPTION_VAL_32_DE NULL

struct retro_core_option_v2_category option_cats_de[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_de[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_DE,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_DE,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_DE },
         { "manual", OPTION_VAL_MANUAL_DE },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_DE,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_DE },
         { "32", OPTION_VAL_32_DE },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_de = {
   option_cats_de,
   option_defs_de
};

/* RETRO_LANGUAGE_EL */

#define LYNX_ROT_SCREEN_LABEL_EL NULL
#define LYNX_ROT_SCREEN_INFO_0_EL NULL
#define OPTION_VAL_AUTO_EL NULL
#define OPTION_VAL_MANUAL_EL NULL
#define LYNX_PIX_FORMAT_LABEL_EL NULL
#define OPTION_VAL_16_EL NULL
#define OPTION_VAL_32_EL NULL

struct retro_core_option_v2_category option_cats_el[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_el[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_EL,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_EL,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_EL },
         { "manual", OPTION_VAL_MANUAL_EL },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_EL,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_EL },
         { "32", OPTION_VAL_32_EL },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_el = {
   option_cats_el,
   option_defs_el
};

/* RETRO_LANGUAGE_EO */

#define LYNX_ROT_SCREEN_LABEL_EO NULL
#define LYNX_ROT_SCREEN_INFO_0_EO NULL
#define OPTION_VAL_AUTO_EO NULL
#define OPTION_VAL_MANUAL_EO NULL
#define LYNX_PIX_FORMAT_LABEL_EO NULL
#define OPTION_VAL_16_EO NULL
#define OPTION_VAL_32_EO NULL

struct retro_core_option_v2_category option_cats_eo[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_eo[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_EO,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_EO,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_EO },
         { "manual", OPTION_VAL_MANUAL_EO },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_EO,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_EO },
         { "32", OPTION_VAL_32_EO },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_eo = {
   option_cats_eo,
   option_defs_eo
};

/* RETRO_LANGUAGE_ES */

#define LYNX_ROT_SCREEN_LABEL_ES "Rotación automática de pantalla"
#define LYNX_ROT_SCREEN_INFO_0_ES "Rota automáticamente la orientación de la pantalla y los controles en aquellos juegos que lo necesiten. Al seleccionar la opción «Manual», la rotación de pantalla se podrá ajustar al pulsar el botón SELECT, en caso contrario, se puede asignar una rotación fija de 0º, 90º, 180º o 270º (en el sentido contrario al de las agujas del reloj)."
#define OPTION_VAL_AUTO_ES "Selección automática"
#define OPTION_VAL_MANUAL_ES "Selección manual"
#define LYNX_PIX_FORMAT_LABEL_ES "Formato de color (es necesario reiniciar)"
#define OPTION_VAL_16_ES "16 bits (RGB565)"
#define OPTION_VAL_32_ES "32 bits (RGB8888)"

struct retro_core_option_v2_category option_cats_es[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_es[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_ES,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_ES,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_ES },
         { "manual", OPTION_VAL_MANUAL_ES },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_ES,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_ES },
         { "32", OPTION_VAL_32_ES },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_es = {
   option_cats_es,
   option_defs_es
};

/* RETRO_LANGUAGE_FA */

#define LYNX_ROT_SCREEN_LABEL_FA NULL
#define LYNX_ROT_SCREEN_INFO_0_FA NULL
#define OPTION_VAL_AUTO_FA NULL
#define OPTION_VAL_MANUAL_FA NULL
#define LYNX_PIX_FORMAT_LABEL_FA NULL
#define OPTION_VAL_16_FA NULL
#define OPTION_VAL_32_FA NULL

struct retro_core_option_v2_category option_cats_fa[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fa[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_FA,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_FA,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_FA },
         { "manual", OPTION_VAL_MANUAL_FA },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_FA,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_FA },
         { "32", OPTION_VAL_32_FA },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_fa = {
   option_cats_fa,
   option_defs_fa
};

/* RETRO_LANGUAGE_FI */

#define LYNX_ROT_SCREEN_LABEL_FI "Näytön automaattinen kierto"
#define LYNX_ROT_SCREEN_INFO_0_FI NULL
#define OPTION_VAL_AUTO_FI "Automaattinen"
#define OPTION_VAL_MANUAL_FI "Manuaalinen"
#define LYNX_PIX_FORMAT_LABEL_FI NULL
#define OPTION_VAL_16_FI NULL
#define OPTION_VAL_32_FI NULL

struct retro_core_option_v2_category option_cats_fi[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fi[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_FI,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_FI,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_FI },
         { "manual", OPTION_VAL_MANUAL_FI },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_FI,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_FI },
         { "32", OPTION_VAL_32_FI },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_fi = {
   option_cats_fi,
   option_defs_fi
};

/* RETRO_LANGUAGE_FR */

#define LYNX_ROT_SCREEN_LABEL_FR "Rotation automatique de l'écran"
#define LYNX_ROT_SCREEN_INFO_0_FR "Faire pivoter automatiquement l'orientation de l'écran et le mappage des touches pour les jeux connus. Lorsque définie sur 'Manuelle', la rotation de l'écran est réglée en appuyant sur la touche SELECT, sinon une rotation fixe peut être réglée à 0, 90, 180 ou 270 degrés dans le sens anti-horaire."
#define OPTION_VAL_AUTO_FR NULL
#define OPTION_VAL_MANUAL_FR "Manuelle"
#define LYNX_PIX_FORMAT_LABEL_FR "Format des couleurs (Redémarrage requis)"
#define OPTION_VAL_16_FR "16 bits (RVB565)"
#define OPTION_VAL_32_FR "32 bits (RVB8888)"

struct retro_core_option_v2_category option_cats_fr[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fr[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_FR,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_FR,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_FR },
         { "manual", OPTION_VAL_MANUAL_FR },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_FR,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_FR },
         { "32", OPTION_VAL_32_FR },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_fr = {
   option_cats_fr,
   option_defs_fr
};

/* RETRO_LANGUAGE_GL */

#define LYNX_ROT_SCREEN_LABEL_GL NULL
#define LYNX_ROT_SCREEN_INFO_0_GL NULL
#define OPTION_VAL_AUTO_GL NULL
#define OPTION_VAL_MANUAL_GL NULL
#define LYNX_PIX_FORMAT_LABEL_GL NULL
#define OPTION_VAL_16_GL NULL
#define OPTION_VAL_32_GL NULL

struct retro_core_option_v2_category option_cats_gl[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_gl[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_GL,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_GL,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_GL },
         { "manual", OPTION_VAL_MANUAL_GL },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_GL,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_GL },
         { "32", OPTION_VAL_32_GL },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_gl = {
   option_cats_gl,
   option_defs_gl
};

/* RETRO_LANGUAGE_HE */

#define LYNX_ROT_SCREEN_LABEL_HE NULL
#define LYNX_ROT_SCREEN_INFO_0_HE NULL
#define OPTION_VAL_AUTO_HE NULL
#define OPTION_VAL_MANUAL_HE NULL
#define LYNX_PIX_FORMAT_LABEL_HE NULL
#define OPTION_VAL_16_HE NULL
#define OPTION_VAL_32_HE NULL

struct retro_core_option_v2_category option_cats_he[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_he[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_HE,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_HE,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_HE },
         { "manual", OPTION_VAL_MANUAL_HE },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_HE,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_HE },
         { "32", OPTION_VAL_32_HE },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_he = {
   option_cats_he,
   option_defs_he
};

/* RETRO_LANGUAGE_HU */

#define LYNX_ROT_SCREEN_LABEL_HU NULL
#define LYNX_ROT_SCREEN_INFO_0_HU NULL
#define OPTION_VAL_AUTO_HU NULL
#define OPTION_VAL_MANUAL_HU NULL
#define LYNX_PIX_FORMAT_LABEL_HU NULL
#define OPTION_VAL_16_HU NULL
#define OPTION_VAL_32_HU NULL

struct retro_core_option_v2_category option_cats_hu[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_hu[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_HU,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_HU,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_HU },
         { "manual", OPTION_VAL_MANUAL_HU },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_HU,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_HU },
         { "32", OPTION_VAL_32_HU },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_hu = {
   option_cats_hu,
   option_defs_hu
};

/* RETRO_LANGUAGE_ID */

#define LYNX_ROT_SCREEN_LABEL_ID NULL
#define LYNX_ROT_SCREEN_INFO_0_ID NULL
#define OPTION_VAL_AUTO_ID NULL
#define OPTION_VAL_MANUAL_ID NULL
#define LYNX_PIX_FORMAT_LABEL_ID NULL
#define OPTION_VAL_16_ID NULL
#define OPTION_VAL_32_ID NULL

struct retro_core_option_v2_category option_cats_id[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_id[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_ID,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_ID,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_ID },
         { "manual", OPTION_VAL_MANUAL_ID },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_ID,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_ID },
         { "32", OPTION_VAL_32_ID },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_id = {
   option_cats_id,
   option_defs_id
};

/* RETRO_LANGUAGE_IT */

#define LYNX_ROT_SCREEN_LABEL_IT "Rotazione Automatica Schermo"
#define LYNX_ROT_SCREEN_INFO_0_IT "Ruota virtualmente l'orientamento dello schermo e i tasti automaticamente per i giochi conosciuti. Quando impostato su 'Manuale', la rotazione dello schermo viene regolata premendo il pulsante SELECT, altrimenti una rotazione fissa può essere impostata a 0, 90, 180 o 270 gradi in senso antiorario."
#define OPTION_VAL_AUTO_IT "Automatico"
#define OPTION_VAL_MANUAL_IT "Manuale"
#define LYNX_PIX_FORMAT_LABEL_IT "Formato Colore (Riavvio Richiesto)"
#define OPTION_VAL_16_IT NULL
#define OPTION_VAL_32_IT NULL

struct retro_core_option_v2_category option_cats_it[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_it[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_IT,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_IT,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_IT },
         { "manual", OPTION_VAL_MANUAL_IT },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_IT,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_IT },
         { "32", OPTION_VAL_32_IT },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_it = {
   option_cats_it,
   option_defs_it
};

/* RETRO_LANGUAGE_JA */

#define LYNX_ROT_SCREEN_LABEL_JA NULL
#define LYNX_ROT_SCREEN_INFO_0_JA NULL
#define OPTION_VAL_AUTO_JA NULL
#define OPTION_VAL_MANUAL_JA NULL
#define LYNX_PIX_FORMAT_LABEL_JA NULL
#define OPTION_VAL_16_JA NULL
#define OPTION_VAL_32_JA NULL

struct retro_core_option_v2_category option_cats_ja[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ja[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_JA,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_JA,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_JA },
         { "manual", OPTION_VAL_MANUAL_JA },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_JA,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_JA },
         { "32", OPTION_VAL_32_JA },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ja = {
   option_cats_ja,
   option_defs_ja
};

/* RETRO_LANGUAGE_KO */

#define LYNX_ROT_SCREEN_LABEL_KO NULL
#define LYNX_ROT_SCREEN_INFO_0_KO NULL
#define OPTION_VAL_AUTO_KO NULL
#define OPTION_VAL_MANUAL_KO NULL
#define LYNX_PIX_FORMAT_LABEL_KO NULL
#define OPTION_VAL_16_KO NULL
#define OPTION_VAL_32_KO NULL

struct retro_core_option_v2_category option_cats_ko[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ko[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_KO,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_KO,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_KO },
         { "manual", OPTION_VAL_MANUAL_KO },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_KO,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_KO },
         { "32", OPTION_VAL_32_KO },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ko = {
   option_cats_ko,
   option_defs_ko
};

/* RETRO_LANGUAGE_MT */

#define LYNX_ROT_SCREEN_LABEL_MT NULL
#define LYNX_ROT_SCREEN_INFO_0_MT NULL
#define OPTION_VAL_AUTO_MT NULL
#define OPTION_VAL_MANUAL_MT NULL
#define LYNX_PIX_FORMAT_LABEL_MT NULL
#define OPTION_VAL_16_MT NULL
#define OPTION_VAL_32_MT NULL

struct retro_core_option_v2_category option_cats_mt[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_mt[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_MT,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_MT,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_MT },
         { "manual", OPTION_VAL_MANUAL_MT },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_MT,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_MT },
         { "32", OPTION_VAL_32_MT },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_mt = {
   option_cats_mt,
   option_defs_mt
};

/* RETRO_LANGUAGE_NL */

#define LYNX_ROT_SCREEN_LABEL_NL "Scherm automatisch draaien"
#define LYNX_ROT_SCREEN_INFO_0_NL NULL
#define OPTION_VAL_AUTO_NL NULL
#define OPTION_VAL_MANUAL_NL NULL
#define LYNX_PIX_FORMAT_LABEL_NL NULL
#define OPTION_VAL_16_NL NULL
#define OPTION_VAL_32_NL NULL

struct retro_core_option_v2_category option_cats_nl[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_nl[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_NL,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_NL,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_NL },
         { "manual", OPTION_VAL_MANUAL_NL },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_NL,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_NL },
         { "32", OPTION_VAL_32_NL },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_nl = {
   option_cats_nl,
   option_defs_nl
};

/* RETRO_LANGUAGE_OC */

#define LYNX_ROT_SCREEN_LABEL_OC NULL
#define LYNX_ROT_SCREEN_INFO_0_OC NULL
#define OPTION_VAL_AUTO_OC NULL
#define OPTION_VAL_MANUAL_OC NULL
#define LYNX_PIX_FORMAT_LABEL_OC NULL
#define OPTION_VAL_16_OC NULL
#define OPTION_VAL_32_OC NULL

struct retro_core_option_v2_category option_cats_oc[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_oc[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_OC,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_OC,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_OC },
         { "manual", OPTION_VAL_MANUAL_OC },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_OC,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_OC },
         { "32", OPTION_VAL_32_OC },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_oc = {
   option_cats_oc,
   option_defs_oc
};

/* RETRO_LANGUAGE_PL */

#define LYNX_ROT_SCREEN_LABEL_PL "Autoobracanie ekranu"
#define LYNX_ROT_SCREEN_INFO_0_PL NULL
#define OPTION_VAL_AUTO_PL NULL
#define OPTION_VAL_MANUAL_PL "Ręcznie"
#define LYNX_PIX_FORMAT_LABEL_PL NULL
#define OPTION_VAL_16_PL NULL
#define OPTION_VAL_32_PL NULL

struct retro_core_option_v2_category option_cats_pl[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pl[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_PL,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_PL,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_PL },
         { "manual", OPTION_VAL_MANUAL_PL },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_PL,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_PL },
         { "32", OPTION_VAL_32_PL },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_pl = {
   option_cats_pl,
   option_defs_pl
};

/* RETRO_LANGUAGE_PT_BR */

#define LYNX_ROT_SCREEN_LABEL_PT_BR "Giro automático da tela"
#define LYNX_ROT_SCREEN_INFO_0_PT_BR "Gira automaticamente a orientação da tela e os controles nos jogos que o requerem. Ao selecionar a opção 'Manual', a rotação da tela pode ser ajustada pressionando o botão SELECT, caso contrário, uma rotação fixa de 0°, 90°, 180° ou 270° no sentido anti-horário pode ser atribuída."
#define OPTION_VAL_AUTO_PT_BR "Automático"
#define OPTION_VAL_MANUAL_PT_BR NULL
#define LYNX_PIX_FORMAT_LABEL_PT_BR "Formato de cor (requer reinício)"
#define OPTION_VAL_16_PT_BR NULL
#define OPTION_VAL_32_PT_BR NULL

struct retro_core_option_v2_category option_cats_pt_br[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_br[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_PT_BR,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_PT_BR },
         { "manual", OPTION_VAL_MANUAL_PT_BR },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_PT_BR,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_PT_BR },
         { "32", OPTION_VAL_32_PT_BR },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_pt_br = {
   option_cats_pt_br,
   option_defs_pt_br
};

/* RETRO_LANGUAGE_PT_PT */

#define LYNX_ROT_SCREEN_LABEL_PT_PT NULL
#define LYNX_ROT_SCREEN_INFO_0_PT_PT NULL
#define OPTION_VAL_AUTO_PT_PT NULL
#define OPTION_VAL_MANUAL_PT_PT NULL
#define LYNX_PIX_FORMAT_LABEL_PT_PT NULL
#define OPTION_VAL_16_PT_PT NULL
#define OPTION_VAL_32_PT_PT NULL

struct retro_core_option_v2_category option_cats_pt_pt[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_pt[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_PT_PT,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_PT_PT },
         { "manual", OPTION_VAL_MANUAL_PT_PT },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_PT_PT,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_PT_PT },
         { "32", OPTION_VAL_32_PT_PT },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_pt_pt = {
   option_cats_pt_pt,
   option_defs_pt_pt
};

/* RETRO_LANGUAGE_RO */

#define LYNX_ROT_SCREEN_LABEL_RO NULL
#define LYNX_ROT_SCREEN_INFO_0_RO NULL
#define OPTION_VAL_AUTO_RO NULL
#define OPTION_VAL_MANUAL_RO NULL
#define LYNX_PIX_FORMAT_LABEL_RO NULL
#define OPTION_VAL_16_RO NULL
#define OPTION_VAL_32_RO NULL

struct retro_core_option_v2_category option_cats_ro[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ro[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_RO,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_RO,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_RO },
         { "manual", OPTION_VAL_MANUAL_RO },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_RO,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_RO },
         { "32", OPTION_VAL_32_RO },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ro = {
   option_cats_ro,
   option_defs_ro
};

/* RETRO_LANGUAGE_RU */

#define LYNX_ROT_SCREEN_LABEL_RU NULL
#define LYNX_ROT_SCREEN_INFO_0_RU NULL
#define OPTION_VAL_AUTO_RU "Авто"
#define OPTION_VAL_MANUAL_RU "Вручную"
#define LYNX_PIX_FORMAT_LABEL_RU NULL
#define OPTION_VAL_16_RU NULL
#define OPTION_VAL_32_RU NULL

struct retro_core_option_v2_category option_cats_ru[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ru[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_RU,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_RU,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_RU },
         { "manual", OPTION_VAL_MANUAL_RU },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_RU,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_RU },
         { "32", OPTION_VAL_32_RU },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ru = {
   option_cats_ru,
   option_defs_ru
};

/* RETRO_LANGUAGE_SI */

#define LYNX_ROT_SCREEN_LABEL_SI NULL
#define LYNX_ROT_SCREEN_INFO_0_SI NULL
#define OPTION_VAL_AUTO_SI NULL
#define OPTION_VAL_MANUAL_SI NULL
#define LYNX_PIX_FORMAT_LABEL_SI NULL
#define OPTION_VAL_16_SI NULL
#define OPTION_VAL_32_SI NULL

struct retro_core_option_v2_category option_cats_si[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_si[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_SI,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_SI,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_SI },
         { "manual", OPTION_VAL_MANUAL_SI },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_SI,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_SI },
         { "32", OPTION_VAL_32_SI },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_si = {
   option_cats_si,
   option_defs_si
};

/* RETRO_LANGUAGE_SK */

#define LYNX_ROT_SCREEN_LABEL_SK NULL
#define LYNX_ROT_SCREEN_INFO_0_SK NULL
#define OPTION_VAL_AUTO_SK NULL
#define OPTION_VAL_MANUAL_SK NULL
#define LYNX_PIX_FORMAT_LABEL_SK NULL
#define OPTION_VAL_16_SK NULL
#define OPTION_VAL_32_SK NULL

struct retro_core_option_v2_category option_cats_sk[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sk[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_SK,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_SK,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_SK },
         { "manual", OPTION_VAL_MANUAL_SK },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_SK,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_SK },
         { "32", OPTION_VAL_32_SK },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_sk = {
   option_cats_sk,
   option_defs_sk
};

/* RETRO_LANGUAGE_SR */

#define LYNX_ROT_SCREEN_LABEL_SR NULL
#define LYNX_ROT_SCREEN_INFO_0_SR NULL
#define OPTION_VAL_AUTO_SR NULL
#define OPTION_VAL_MANUAL_SR NULL
#define LYNX_PIX_FORMAT_LABEL_SR NULL
#define OPTION_VAL_16_SR NULL
#define OPTION_VAL_32_SR NULL

struct retro_core_option_v2_category option_cats_sr[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sr[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_SR,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_SR,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_SR },
         { "manual", OPTION_VAL_MANUAL_SR },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_SR,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_SR },
         { "32", OPTION_VAL_32_SR },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_sr = {
   option_cats_sr,
   option_defs_sr
};

/* RETRO_LANGUAGE_SV */

#define LYNX_ROT_SCREEN_LABEL_SV NULL
#define LYNX_ROT_SCREEN_INFO_0_SV NULL
#define OPTION_VAL_AUTO_SV NULL
#define OPTION_VAL_MANUAL_SV NULL
#define LYNX_PIX_FORMAT_LABEL_SV NULL
#define OPTION_VAL_16_SV NULL
#define OPTION_VAL_32_SV NULL

struct retro_core_option_v2_category option_cats_sv[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sv[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_SV,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_SV,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_SV },
         { "manual", OPTION_VAL_MANUAL_SV },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_SV,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_SV },
         { "32", OPTION_VAL_32_SV },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_sv = {
   option_cats_sv,
   option_defs_sv
};

/* RETRO_LANGUAGE_TR */

#define LYNX_ROT_SCREEN_LABEL_TR "Ekranı Otomatik Döndür"
#define LYNX_ROT_SCREEN_INFO_0_TR NULL
#define OPTION_VAL_AUTO_TR NULL
#define OPTION_VAL_MANUAL_TR NULL
#define LYNX_PIX_FORMAT_LABEL_TR NULL
#define OPTION_VAL_16_TR NULL
#define OPTION_VAL_32_TR NULL

struct retro_core_option_v2_category option_cats_tr[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_tr[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_TR,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_TR,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_TR },
         { "manual", OPTION_VAL_MANUAL_TR },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_TR,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_TR },
         { "32", OPTION_VAL_32_TR },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_tr = {
   option_cats_tr,
   option_defs_tr
};

/* RETRO_LANGUAGE_UK */

#define LYNX_ROT_SCREEN_LABEL_UK NULL
#define LYNX_ROT_SCREEN_INFO_0_UK NULL
#define OPTION_VAL_AUTO_UK NULL
#define OPTION_VAL_MANUAL_UK NULL
#define LYNX_PIX_FORMAT_LABEL_UK NULL
#define OPTION_VAL_16_UK NULL
#define OPTION_VAL_32_UK NULL

struct retro_core_option_v2_category option_cats_uk[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_uk[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_UK,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_UK,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_UK },
         { "manual", OPTION_VAL_MANUAL_UK },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_UK,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_UK },
         { "32", OPTION_VAL_32_UK },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_uk = {
   option_cats_uk,
   option_defs_uk
};

/* RETRO_LANGUAGE_VN */

#define LYNX_ROT_SCREEN_LABEL_VN NULL
#define LYNX_ROT_SCREEN_INFO_0_VN NULL
#define OPTION_VAL_AUTO_VN NULL
#define OPTION_VAL_MANUAL_VN NULL
#define LYNX_PIX_FORMAT_LABEL_VN NULL
#define OPTION_VAL_16_VN NULL
#define OPTION_VAL_32_VN NULL

struct retro_core_option_v2_category option_cats_vn[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_vn[] = {

   /* These variable names and possible values constitute an ABI with ZMZ (ZSNES Libretro player).
    * Changing "Show layer 1" is fine, but don't change "layer_1"/etc or the possible values ("Yes|No").
    * Adding more variables and rearranging them is safe. */

   {
      "lynx_rot_screen",
      LYNX_ROT_SCREEN_LABEL_VN,
      NULL,
      LYNX_ROT_SCREEN_INFO_0_VN,
      NULL,
      NULL,
      {
         { "auto", OPTION_VAL_AUTO_VN },
         { "manual", OPTION_VAL_MANUAL_VN },
         { "0",    NULL },
         { "90",   NULL },
         { "180",  NULL },
         { "270",  NULL },
         { NULL, NULL},
      },
      "auto",
   },

   {
      "lynx_pix_format",
      LYNX_PIX_FORMAT_LABEL_VN,
      NULL,
      "",
      NULL,
      NULL,
      {
         { "16", OPTION_VAL_16_VN },
         { "32", OPTION_VAL_32_VN },
         { NULL, NULL},
      },
      "16",
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_vn = {
   option_cats_vn,
   option_defs_vn
};


#ifdef __cplusplus
}
#endif

#endif