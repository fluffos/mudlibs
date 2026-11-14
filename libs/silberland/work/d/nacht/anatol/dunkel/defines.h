/* preprocessor definitions for the darkest dark
 * ____________________________________(i) Anatol@Silberland (1999-2012) */

#include "../defines.h"

#pragma strict_types

#ifndef _DUNKEL_H_
#define _DUNKEL_H_

// "root directory"

#define DUNKEL 	ANATOL_NACHT "dunkel/"



#define DUNKEL_ROOM DUNKEL "r/"
#ifdef ROOM
#undef ROOM
#endif
#define ROOM DUNKEL_ROOM

#define DUNKEL_NPC DUNKEL "n/"
#ifdef NPC
#undef NPC
#endif
#define NPC DUNKEL_NPC

#define DUNKEL_OBJ DUNKEL "t/"
#ifdef OBJ
#undef OBJ
#endif
#define OBJ DUNKEL_OBJ

#define DUNKEL_ARMOUR DUNKEL "a/"
#ifdef ARMOUR
#undef ARMOUR
#endif
#define ARMOUR DUNKEL_ARMOUR

#define DUNKEL_WEAPON DUNKEL "w/"
#ifdef WEAPON
#undef WEAPON
#endif
#define WEAPON DUNKEL_WEAPON

// Fuer Log einen extra Verzeichnisbaum. Wenn mal ein File volllaeuft,
// soll man es schnell finden koennen.

#define DUNKEL_LOG ANATOL_NACHT_LOG "dunkel/"
#ifdef LOG
#undef LOG
#endif
#define LOG DUNKEL_LOG

#define DUNKEL_SAVE DUNKEL "save/"

#endif
