/* 08/17/06 Earwax: This is being set to replace all the misc 
 * includes.  It's perhaps not the best way to do it, but it's 
 * better than the existing method.
 */

/* Formerly /obj/lib/security/private.h */
/* This probably will have to be yanked, I just have to find all the
 * occurances of the 'private' definition.  No wonder simul_efun 
 * was shitting itself when I tried to use it there.
 */
/* object access */
#ifndef private
#define private if (this_player() != this_object()) return 0
#endif

/* Formerly /obj/lib/security/wiz_levels.h, standard_security.h,
 * and file_acs.h 
 */
/* standard security */
#ifndef EXPLORE
#define EXPLORE 20
#endif

#ifndef CREATE
#define CREATE 21
#endif

#ifndef TITLE
#define TITLE 21
#endif

#ifndef INVIS
#define INVIS 30
#endif

#ifndef STAT
#define STAT 40
#endif

#ifndef OUT_OF_BODY
#define OUT_OF_BODY 50
#endif

#ifndef CONTROL
#define CONTROL 50
#endif

#ifndef SNOOP
#define SNOOP 60
#endif

#ifndef DAMAGE
#define DAMAGE 70
#endif

#ifndef ITEM_OVER
#define ITEM_OVER 80
#endif

#ifndef ECHO
#define ECHO 40
#endif

#ifndef SHUTDOWN
#define SHUTDOWN 1000
#endif

#ifndef EDIT_STANDARD
#define EDIT_STANDARD 1000
#endif

#ifndef ALL_POWER
#define ALL_POWER GOD
#endif



/* Formerly /obj/lib/security/invis.h */
/* invisability */
#ifndef NO_SHORT
#define NO_SHORT 17
#endif

#ifndef NO_MOVE
#define NO_MOVE 19
#endif

#ifndef CAN_NO_SHORT
#define CAN_NO_SHORT 30
#endif

#ifndef NO_WHO
#define NO_WHO 20
#endif

#ifndef CAN_NO_WHO
#define CAN_NO_WHO 35
#endif

#ifndef SOMEONE
#define SOMEONE 30
#endif

#ifndef CAN_SOMEONE
#define CAN_SOMEONE 40
#endif

#ifndef INVIS_TELEPORT
#define INVIS_TELEPORT 40
#endif

#ifndef CAN_INVIS_TELEPORT
#define CAN_INVIS_TELEPORT 60
#endif

#ifndef INVIS_ACTION
#define INVIS_ACTION 50
#endif

#ifndef CAN_INVIS_ACTION
#define CAN_INVIS_ACTION 100
#endif

#ifndef NO_ID
#define NO_ID 60
#endif

#ifndef CAN_NO_ID
#define CAN_NO_ID 300
#endif

#ifndef NO_PEOPLE
#define NO_PEOPLE 100
#endif

#ifndef CAN_NO_PEOPLE
#define CAN_NO_PEOPLE 600
#endif

/* to make life easier */
#ifndef INV1
#define INV1 NO_SHORT
#endif

#ifndef CINV1
#define CINV1 CAN_NO_SHORT
#endif

#ifndef INV2
#define INV2 NO_WHO
#endif

#ifndef CINV2
#define CINV2 CAN_NO_WHO
#endif

#ifndef INV3
#define INV3 SOMEONE
#endif

#ifndef CINV3
#define CINV3 CAN_SOMEONE
#endif

#ifndef INV4
#define INV4 INVIS_TELEPORT
#endif

#ifndef CINV4
#define CINV4 CAN_INVIS_TELEPORT
#endif

#ifndef INV5
#define INV5 INVIS_ACTION
#endif

#ifndef CINV5
#define CINV5 CAN_INVIS_ACTION
#endif

#ifndef INV6
#define INV6 NO_ID
#endif

#ifndef CINV6
#define CINV6 CAN_NO_ID
#endif

#ifndef INV7
#define INV7 NO_PEOPLE
#endif

#ifndef CINV7
#define CINV7 CAN_NO_PEOPLE
#endif


/* Formerly /obj/lib/security/id.h */
#ifndef PLAYER_ID
#define PLAYER_ID "GlobalPlayerId"
#endif

#ifndef PLAYERID
#define PLAYERID PLAYER_ID
#endif

