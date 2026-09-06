#ifndef _SILVERE_PATH_H_
#define _SILVERE_PATH_H_ 1

/*--------------------------------------------------------------------------
 * /d/silvere/sys/path.h -- Macros for standard pathnames in /d/silvere
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * This file is included by /d/silvere/sys/silvere.h, which in addition
 * holds property definitions and other useful stuff.
 */

/* start with the main path for easy moving of the files */
#define BASE                 "/d/silvere/"
#define STD(x)               BASE "std/" x
#define ROOM                 BASE "rooms/"
#define OBJ(x)               BASE "obj/" x
#define NPC(x)               BASE "npc/" x
#define LOG(x)               BASE "log/" x
#define TXT(x)               BASE "doc/player/" x

/* areas */
#define COAST(x)             ROOM "coast/" x
#define SILVERE(x)           ROOM x
#define SIL_HARBOUR(x)       SILVERE("harbour/" x)
#define SIL_PALACE(x)        SILVERE("palace/" x)
#define SIL_CENTER(x)        SILVERE("center/" x)
#define SIL_PARK(x)          SILVERE("newbiepark/" x)
#define SIL_WEST(x)          SILVERE("west/" x)
#define SIL_EAST(x)          SILVERE("east/" x)
#define SIL_SOUTH(x)         SILVERE("south/" x)
#define SIL_NORTH(x)         SILVERE("north/" x)
#define SIL_FOREST(x)        SILVERE("forest/" x)
#define SIL_FIELDS(x)        SILVERE("fields/" x)
#define PARCH_CAVE(x)        SILVERE("caves/" x)
#define SIL_CORNFIELD(x)     SILVERE("corn/" x)
#define SIL_FORTRESS(x)      SILVERE("fortress/" x)

/* Weapons and Armour paths */
#define WEAPONS(x)           OBJ("weapons/" x)
#define ARMOUR(x)            OBJ("armour/" x)

/* some useful defines */
#define BASEROOM             STD("room")
#define HARBOUR_BASEROOM     STD("harbour_room")
#define SILBASEROOM          STD("cityroom")
#define SILCAVEROOM          STD("caveroom")
#define SILCORNFIELD         STD("basecornfield")

#endif /* _SILVERE_PATH_H_ */
