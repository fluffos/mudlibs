// SilberLand MUDlib
//
// sys/room/description.h -- room description header
//
// $Date: 2012/02/01 09:29:10 $
/* $Revision: 2.11 $
 * $Log: description.h,v $
 * Revision 2.11  2012/02/01 09:29:10  Woody
 * Neu: RemoveRoomMessage()
 *
 * Revision 2.10  2003/12/26 01:02:41  Woody
 * MSGFLAG_* nach thing/description.h verlegt
 *
 * Revision 2.9  2003/12/19 01:19:31  Woody
 * MSGFLAG_EXTRA_* -> MSGFLAG_(IN/EX)CLUDE, MSGFLAG_PERM_FUNC
 *
 * Revision 2.8  2003/12/19 00:41:42  Woody
 * Neu: MSGFLAG_EXTRA_INCLUDE
 *
 * Revision 2.7  2003/12/19 00:36:53  Woody
 * Neu: MSGFLAG_EXTRA_EXCLUDE
 *
 * Revision 2.6  2000/07/05 15:18:14  Woody
 * MSGFLAG_NO_TP definiert
 *
 * Revision 2.5  1999/09/16 10:02:24  Woody
 * MSGFLAG_* Defines fuer Raeume
 *
 * Revision 2.4  1999/01/09 20:51:48  Woody
 * P_SEER_HOUSE rausgeworfen
 *
 * Revision 2.3  1998/01/13 07:49:14  Crea
 * P_WANTS_TO_LEARN Flags for wiz_header
 *
 * Revision 2.2  1997/03/31 15:36:44  Woody
 * prepared for revision control
 *
 * Revision 2.1  1996/09/22  17:15:00  Woody
 * P_SEER_HOUSE
 *
 * Revision 2.0  1996/04/17  11:50:00  Woody
 * Details in sys/thing/description.h umgelagert
 *
 * Revision 1.5  1996/03/12  17:05:00  Mupfel
 * Details etc. aus /sys/properties.h
 *
 * Revision 1.4  1996/03/11  02:34:00  Mupfel
 * prototypes added, P_HAUS_ERLAUBT removed
 *
 * Revision 1.3  1994/10/05  12:07:39  Jof
 * seherhaeuser
 *
 * Revision 1.2  1994/02/08  17:32:41  Hate
 * *** empty log message ***
 *
 */
 
#ifndef __ROOM_DESCRIPTION_H__
#define __ROOM_DESCRIPTION_H__

// properties

#define P_INT_SHORT "int_short"
#define P_INT_LONG  "int_long"

#define P_ROOM_MSG  "room_msg"
#define P_FUNC_MSG  "func_msg"
#define P_MSG_PROB  "msg_prob"

#define P_SOUNDS          "sounds"
#define P_SMELLS          "smells"

#define P_TRANSPORTERS    "transporters"

// Default-Geruch und -Geraeusch

#define DEFAULT_SMELL  "\ndefault"
#define DEFAULT_SOUND  "\ndefault"

// P_WANTS_TO_LEARN Flags

#define NW_HEADER       8

#endif // __ROOM_DESCRIPTION_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_DESCRIPTION_H_PROTO__
#define __ROOM_DESCRIPTION_H_PROTO__

// prototypes
void AddRoomMessage(mixed *mesg, int prob, mixed *func);
void RemoveRoomMessage(mixed *mesg);

void AddSmell(mixed *keys, mixed descr);
void RemoveSmell(mixed *keys);
void AddSound(mixed *keys, mixed descr);
void RemoveSound(mixed *keys);

varargs string GetSmell(mixed key, mixed race);
varargs string GetSound(mixed key, mixed race);

#endif // __ROOM_DESCRIPTION_H_PROTO__

#endif	// NEED_PROTOYPES
