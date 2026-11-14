// SilberLand MUDlib
//
// sys/room/houses.h -- room seer houses handling header
//
// $Date: 2001/02/17 10:10:36 $
/* $Revision: 1.2 $
 * $Log: houses.h,v $
 * Revision 1.2  2001/02/17 10:10:36  Woody
 * SEERHOUSEMASTER liegt jetzt in /p/daemon/housed/housed
 *
 * Revision 1.1  1999/01/09 20:52:54  Woody
 * Initial revision
 *
 */
 
#ifndef __ROOM_HOUSES_H__
#define __ROOM_HOUSES_H__

// properties
#define P_SEER_HOUSE    "seer_house"    // Mapping exits:uid(besitzer)||0

// master
#define SEERHOUSEMASTER     "/p/daemon/housed/housed"
#define SEERHOUSE_PATH      "/d/seher/haus/"

// symbolic indices
#define QH_FILENAME     0       // as used by QueryHouses()
#define QH_DIRECTION    1       // ...

#endif // __ROOM_HOUSES_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_HOUSES_H_PROTO__
#define __ROOM_HOUSES_H_PROTO__

// prototypes
public int CheckForHouses();

#endif // __ROOM_HOUSES_H_PROTO__

#endif	// NEED_PROTOYPES

