// SilberLand MUDlib
//
// sys/player/comm.h -- communication module properties
//
// $Date: 2003/12/26 01:02:20 $
/* $Revision: 2.14 $
 * $Log: comm.h,v $
 * Revision 2.14  2003/12/26 01:02:20  Woody
 * MSGFLAG_* nach thing/description.h verlegt
 *
 * Revision 2.13  2003/07/02 01:26:20  Woody
 * MSGFLAG_SHIST, MSGFLAG_THIST
 *
 * Revision 2.12  2001/01/22 11:00:33  Woody
 * DEAF_END_MSG definiert
 *
 * Revision 2.11  2000/10/18 13:13:51  Woody
 * MSGFLAG_HIST eingefuehrt (welche Messages landen in der History?)
 *
 * Revision 2.10  1999/09/16 10:01:01  Woody
 * Message() prototype entfernt (ist jetzt in sys/thing/description)
 *
 * Revision 2.9  1998/08/22 17:00:23  Woody
 * MSGFLAG_SILENT definiert
 *
 * Revision 2.8  1998/01/24 19:53:49  Feyaria
 * DEAF_MSG, DEAF_TIME
 *
 * Revision 2.7  1997/06/25 12:16:43  Woody
 * Flags und Konstanten fuer neues Message()
 *
 * Revision 2.6  1997/03/31 15:01:29  Woody
 * prepared for revision control
 *
 * Revision 2.5  1996/10/03  Woody
 * P_PERM_STRING
 *
 * Revision 2.4  1995/07/25  08:54:43  Wargon
 * P_DEAF
 *
 * Revision 2.3  1995/06/13  14:07:22  Hate
 * *** empty log message ***
 *
 * Revision 2.2  1994/04/20  16:51:19  Jof
 * INTERMUD
 *
 * Revision 2.1  1994/01/20  16:17:23  Jof
 * CAN_ECHO changed to CANECHO
 *
 * Revision 2.0  1994/01/20  16:09:46  Jof
 * NEW !
 *
 * Revision 1.2  1994/01/06  12:00:30  mud
 * *** empty log message ***
 *
 * Revision 1.1  1994/01/06  10:46:59  mud
 * Initial revision
 *
 */
 
#ifndef __PLAYER_COMM_H__
#define __PLAYER_COMM_H__

// properties

#define P_INTERMUD      "intermud"      // Does she listen to it ?
#define P_BUFFER        "buffer"        // ignore-, tell-buffer 
#define P_DEAF          "deaf"          // Taubheit
#define DEAF_TIME       "deaf_time"     // Zeit, wie lange man nich taub ist 
#define DEAF_MSG        "deaf_msg"      // Text, der ausgegeben wird
#define DEAF_END_MSG    "deaf_end_msg"  // Text, der am Ende ausgegeben wird
#define P_PERM_STRING   "perm_string"	// Permutiere String (f.Sprachflueche)

#endif // __PLAYER_COMM_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_COMM_H_PROTO__
#define __PLAYER_COMM_H_PROTO__ 

// prototypes

#endif // __PLAYER_COMM_H_PROTO__

#endif // NEED_PROTOYPES

