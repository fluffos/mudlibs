// SilberLand MUDlib
//
// sys/player/comm.h -- communication module properties
//
// $Date: 1998/01/24 19:53:49 $
/* $Revision: 2.8 $
 * $Log: comm.h,v $
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

#define P_INTERMUD      "intermud" // Does she listen to it ?
#define P_BUFFER        "buffer"   // ignore-, tell-buffer 
#define P_DEAF          "deaf"     // Taubheit
#define DEAF_TIME       "deaf_time"// Zeit, wie lange man nich taub ist 
#define DEAF_MSG        "deaf_msg" // String, der ausgegeben wird
#define P_PERM_STRING   "perm_string"	// Permutiere String (f.Sprachflueche)

// definitions for Message()

#define MSGFLAG_CHANNEL 0x0001  // messages from channeld.c
#define MSGFLAG_CHIST   0x0002
#define MSGFLAG_SOUL    0x0004  // messages from soul.c
#define MSGFLAG_REMOTE  0x0008  // remote emotes
#define MSGFLAG_SHOUT   0x0010  // communication commands
#define MSGFLAG_TELL    0x0020
#define MSGFLAG_SAY     0x0040
#define MSGFLAG_WHISPER 0x0080
#define MSGFLAG_MECHO   0x0100
#define MSGFLAG_RTELL   0x0200  // tell from other mud

// Was geht in den Kobold?
#define MSGFLAG_CACHE   (MSGFLAG_TELL | MSGFLAG_REMOTE | \
                         MSGFLAG_WHISPER | MSGFLAG_RTELL)

#define MSGFLAG_DEAFCHK (MSGFLAG_SHOUT | MSGFLAG_TELL | MSGFLAG_SAY \
        | MSGFLAG_WHISPER | MSGFLAG_CHANNEL | MSGFLAG_RTELL)

// Rueckgabewerte von Message()
#define MESSAGE_OK           1  // alles klar
#define MESSAGE_CACHE        0  // Meldung steht im Kobold
#define MESSAGE_IGNORE_YOU  -1  // Meldung/Sender wird ignoriert
#define MESSAGE_IGNORE_VERB -2
#define MESSAGE_IGNORE_MUD  -3
#define MESSAGE_DEAF        -4  // Empfaenger hoert nicht zu
#define MESSAGE_CACHE_FULL  -5  // Kobold kann nichts mehr merken

#endif // __PLAYER_COMM_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_COMM_H_PROTO__
#define __PLAYER_COMM_H_PROTO__ 

// prototypes

varargs int Message(string msg, int flag);
nosave void modify_prompt();

#endif // __PLAYER_COMM_H_PROTO__

#endif // NEED_PROTOYPES

