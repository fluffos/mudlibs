// SilberLand MUDlib
//
// sys/room/description.h -- room description header
//
// $Date: 1998/01/13 07:49:14 $
/* $Revision: 2.3 $
 * $Log: description.h,v $
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

// Default-Geruch und -Geraeusch

#define DEFAULT_SMELL  "\ndefault"
#define DEFAULT_SOUND  "\ndefault"

// Seherhaus: Mapping exits:uid(besitzer)||0
// zB. ([ "norden":"woody", "sueden":0, "westen":"tester" ])

#define P_SEER_HOUSE	"seer_house"

// P_WANTS_TO_LEARN Flags

#define NW_HEADER       8

#endif // __ROOM_DESCRIPTION_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_DESCRIPTION_H_PROTO__
#define __ROOM_DESCRIPTION_H_PROTO__

// prototypes
void AddRoomMessage(string *mesg, int prob, mixed *func);

void AddSmell(mixed *keys, mixed descr);
void RemoveSmell(mixed *keys);
void AddSound(mixed *keys, mixed descr);
void RemoveSound(mixed *keys);

// varargs string GetSmell(mixed key, mixed race);
// varargs string GetSound(mixed key, mixed race);

#endif // __ROOM_DESCRIPTION_H_PROTO__

#endif	// NEED_PROTOYPES
