// SilberLand MUDlib
//
// sys/room.h -- room defines
//
// $Date: 1999/01/09 20:50:52 $
/* $Revision: 1.2 $
 * $Log: room.h,v $
 * Revision 1.2  1999/01/09 20:50:52  Woody
 * included room/houses.h
 *
 * Revision 1.1  1997/03/31 13:31:16  Woody
 * prepared for revision control
 *
 * Revision 1.0  1996/03/11  02:02:00  Mupfel
 * Entstanden aus /sys/rooms.h. Das 'alte' /sys/room.h
 * ist wohl ein uralt-Relikt und wurde entfernt
 *
 */
 
#ifndef __ROOM_H__
#define __ROOM_H__

#include <room/description.h>
#include <room/exits.h>
#include <room/items.h>
#include "room/doors.h"
#include <room/houses.h>

// defines
// values for teleport forbid property
#define TPORT_IN   1
#define TPORT_OUT  2
#define TPORT_BOTH (TPORT_IN | TPORT_OUT)

// properties

#endif // __ROOM_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_H_PROTO__
#define __ROOM_H_PROTO__

// prototypes
// no prototypes

#endif // __ROOM_H_PROTO__

#endif	// NEED_PROTOYPES
