/* preprocessor definitions for race changes
 * ____________________________________(i) Anatol@Silberland (1999-2012) */

#include "../defines.h"

#pragma strict_types

#ifndef _DOVENYA_H_
#define _DOVENYA_H_

// "root directory"

#define DOVENYA 	ANATOL_NACHT "dovenya/"


#define P_DOVENYA_GEOMETRY "dovenya_geometry"

#define DOVENYA_ROOM DOVENYA "r/"
#ifdef ROOM
#undef ROOM
#endif
#define ROOM DOVENYA_ROOM

#define DOVENYA_NPC DOVENYA "n/"
#ifdef NPC
#undef NPC
#endif
#define NPC DOVENYA_NPC

#define DOVENYA_OBJ DOVENYA "o/"
#ifdef OBJ
#undef OBJ
#endif
#define OBJ DOVENYA_OBJ

#define DOVENYA_ARMOUR DOVENYA "a/"
#ifdef ARMOUR
#undef ARMOUR
#endif
#define ARMOUR DOVENYA_ARMOUR

#define DOVENYA_WEAPON DOVENYA "w/"
#ifdef WEAPON
#undef WEAPON
#endif
#define WEAPON DOVENYA_WEAPON

// Fuer Log einen extra Verzeichnisbaum. Wenn mal ein File volllaeuft,
// soll man es schnell finden koennen.

#define DOVENYA_LOG ANATOL_NACHT_LOG "dovenya/"
#ifdef LOG
#undef LOG
#endif
#define LOG DOVENYA_LOG

#define DOVENYA_SAVE DOVENYA "save/"

#endif
