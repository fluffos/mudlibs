// SilberLand MUDlib
//
// sys/player/viewcmd.h -- view command handling
//
// $Date: 2003/09/30 17:04:28 $
/* $Revision: 1.6 $
 * $Log: viewcmd.h,v $
 * Revision 1.6  2003/09/30 17:04:28  Feyaria
 * BRIEF_TITLE
 *
 * Revision 1.5  2001/01/22 10:58:37  Woody
 * BLIND_END_MSG definiert
 *
 * Revision 1.4  1998/01/24 19:55:48  Feyaria
 * BLIND_TIME, BLIND_MSG
 *
 * Revision 1.3  1997/03/31 15:19:15  Woody
 * prepared for revision control
 *
 * Revision 1.2  97/02/27  15:40:00 Woody
 * BRIEF_* Konstanten
 *
 * Revision 1.1  96/05/25  19:00:00 Woody
 * P_COLUMN_MODE eingefuehrt
 *
 * Revision 1.0  22/02/96  23:00:00 Hadra
 * P_SHORTINV eingefuehrt
 */
 
#ifndef __PLAYER_VIEWCMD_H__
#define __PLAYER_VIEWCMD_H__

// properties

#define P_BLIND         "blind"
#define BLIND_TIME      "blind_time"    // Zeit, die lange man noch blind ist
#define BLIND_MSG       "blind_msg"     // Meldung, die ausgegeben wird
#define BLIND_END_MSG   "blind_end_msg" // Meldung, die am Ende ausgeg. wird

#define P_BRIEF         "brief"
#define P_SHORTINV      "shortinv"
#define P_COLUMN_MODE   "column_mode"

// bitmasks/flags

#define BRIEF_VMASK     15      // view mask
#define BRIEF_FMASK     240     // fight mask
#define BRIEF_FNOATTACK 16      // don't show attack messages
#define BRIEF_FNODAMAGE 32      // don't show damage messages
#define BRIEF_TITLE     1024    // show presay/title instead of race/guild_title 

#endif // __PLAYER_VIEWCMD_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_VIEWCMD_H_PROTO__     
#define __PLAYER_VIEWCMD_H_PROTO__

// prototypes
// no prototypes

#endif // __PLAYER_VIEWCMD_H_PROTO__

#endif // NEED_PROTOYPES
