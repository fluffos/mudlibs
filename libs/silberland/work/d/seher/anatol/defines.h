// defines.h in /d/seher/anatol
// (c) 1998 Adrian Holzwarth / Anatol@Silberland

#include <properties.h>
#include <moving.h>
#include <wizlevels.h>
#include <language.h>

#pragma strict_types

#ifndef _SEHER_H_
#define _SEHER_H_

#define LOGTIME (dtime(time())[5..])

#define LOG        "/wiz/anatol/seher/"  /* Fuer log_file()! */
#define SEHER      "/d/seher/anatol/"
#define ROOM       SEHER "r/"
#define NPC        SEHER "n/"
#define OBJ        SEHER "o/"
#define THING      SEHER "t/"
#define MASTERDIR  SEHER "master/"
#define WEAPON     SEHER "w/"
#define ARMOUR     SEHER "a/"
#define TOOLS      SEHER "tools/"
#define OWNSAVE    SEHER "save/"
#define STD        SEHER "std/"
#define PROJECT    SEHER "p/"

#ifndef P_GEMA
#define P_GEMA "generic_map"
#endif

// Einige Defines, die das Debuggen erleichtern koennen:

//#define DEBUG_MESSAGE( key, level, text ) catch(call_other("/players/anatol/r/debug","I", key, level, text))
#endif
