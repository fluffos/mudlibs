/*  -*- LPC -*-  */
/*
 * Standard files in our mudlib.
 *
 * The define prefixes are as follows:
 *
 *   D_   A daemon object
 *   I_   File to inherit/clone
 *   R_   An important room
 *
 * You can usually use I_ names for cloning as well, but you can not depend
 * on C_ names being inheritable.
 *
 */

#ifndef _MUDLIB_H
#define _MUDLIB_H

#ifndef __STD_FILES__
#define __STD_FILES__
#endif

#ifndef __NANNYMUD__
#define __NANNYMUD__
#endif

/* STD FILES */

#define I_BASIC      "/std/basic"
#define I_ROOM       "/std/basic_room"
#define I_TREASURE   "/std/basic_thing"
#define I_ITEM       "/std/stationary"
#define I_ARMOUR     "/std/simple_armour"
#define I_WEAPON     "/std/simple_weapon"
#define I_CONTAINER  "/std/container"

#define D_LIB        "/std/lib"

#define R_QUEST_ROOM "/room/quest_room"

#endif
