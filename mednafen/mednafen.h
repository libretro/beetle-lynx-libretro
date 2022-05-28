#ifndef _MEDNAFEN_H
#define _MEDNAFEN_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "git.h"

#include "mednafen-types.h"
#include "settings.h"

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

extern MDFNGI *MDFNGameInfo;

void MDFN_LoadGameCheats(void);
void MDFN_FlushGameCheats(void);

#endif
