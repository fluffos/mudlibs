#ifndef _SYKORATH_SYS_PATH_H_
#define _SYKORATH_SYS_PATH_H_ 1

/*--------------------------------------------------------------------------
 * /d/sykorath/sys/path.h -- Macros for standard pathnames in /d/sykorath
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * This file is included by /d/sykorath/sys/sykorath.h, which in addition
 * holds property definitions and other useful stuff.
 */

/* start with the main path for easy moving of the files */
#define BASE                 "/d/sykorath/"
#define STD(x)               BASE+"std/"+x
#define ROOM                 BASE+"rooms/"
#define QUEST(x)             BASE+"quests/"+x
#define OBJ(x)               BASE+"obj/"+x
#define NPC(x)               BASE+"npc/"+x
#define LOG(x)               BASE+"log/"+x

#define TXT(x)               BASE+"doc/player/"+x

/* areas */
#define DFOREST(x)           ROOM+"dforest/"+x

#define INNER(x)             ROOM+"inner/"+x
#define OUTER(x)             ROOM+"outer/"+x
#define SEAROOMS(x)          ROOM+"sea/"+x
#define TUNNELS(x)           ROOM+"tunnels/"+x
#define NEWBIE(x)            ROOM+"newbiepark/"+x
#define UNDERGROUND(x)       ROOM+"underground/"+x
#define TOWNWALLI(x)         INNER("townwall/")+x
#define TOWNWALLO(x)         OUTER("townwall/")+x

/*
   old define - remove it if all rooms moved to inner and outer
   city directories
*/
#define SYKORATH(x)          ROOM+x

/* some useful defines */
#define BASEROOM             STD("room")
#define SY_STREET            STD("sy_street")
#define TOWNWALL             STD("townwall")

#endif /* _SYKORATH_SYS_PATH_H_ */
