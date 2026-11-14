/* preprocessor definitions for race changes
 * ____________________________________(i) Anatol@Silberland (1999-2012) */

#include "../defines.h"

#pragma strict_types

#ifndef _RACE_CHANGE_H_
#define _RACE_CHANGE_H_

// "root directory"

#define RASSENWECHSEL 	ANATOL_NACHT "rassen/"
#define SEQUENCES_DIR RASSENWECHSEL "sequences/"

#ifndef P_LAST_RACE_CHANGE
#define P_LAST_RACE_CHANGE "last_race_change"
#endif

#define RASSENWECHSEL_ROOM RASSENWECHSEL "r/"
#ifdef ROOM
#undef ROOM
#endif
#define ROOM RASSENWECHSEL_ROOM

#define RASSENWECHSEL_NPC RASSENWECHSEL "n/"
#ifdef NPC
#undef NPC
#endif
#define NPC RASSENWECHSEL_NPC

#endif
