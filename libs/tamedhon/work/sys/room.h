// SilberLand MUDlib
//
// sys/room.h -- room defines
//
// 2024/04/09 - includes als absolutpfad, damit auch das masterobjekt laden kann - Aloy
//
// $Date: 1997/03/31 13:31:16 $
/* $Revision: 1.1 $
 * $Log: room.h,v $
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

#include "/sys/room/description.h"
#include "/sys/room/exits.h"
#include "/sys/room/items.h"
#include "/sys/room/doors.h"

// properties
// Flags fuer Einschraenkung der Daten fuer Mappingzwecke an den Client
#define P_MAP_RESTRICTIONS  "lib_p_map_restrictions"

// defines
// values for teleport forbid property
#define TPORT_IN   1
#define TPORT_OUT  2
#define TPORT_BOTH (TPORT_IN | TPORT_OUT)

// Werte fuer P_MAP_RESTRICTIONS
#define MR_NOUID  0x1
#define MR_NOINFO 0x2

// properties

#endif // __ROOM_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_H_PROTO__
#define __ROOM_H_PROTO__

// prototypes
// no prototypes

#endif // __ROOM_H_PROTO__

#endif	// NEED_PROTOYPES
