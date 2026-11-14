// SilberLand MUDlib
//
// sys/room/items.h -- extra room items handling
//
// $Date: 1997/06/25 12:17:04 $
/* $Revision: 1.2 $
 * $Log: items.h,v $
 * Revision 1.2  1997/06/25 12:17:04  Woody
 * REFRESH_INIT, RemoveItem() Prototyp
 *
 * Revision 1.1  1997/03/31 15:41:48  Woody
 * prepared for revision control
 *
 * Revision 1.0	 1996/03/11 01:55:00	Mupfel
 * P_ITEMS von /sys/properties.h, Konstanten aus /sys/rooms.h 'verlegt'
 *
 */
 
#ifndef __ROOM_ITEMS_H__
#define __ROOM_ITEMS_H__

// properties

#define P_ITEMS "items"

// entries in item array
#define RITEM_OBJECT  0
#define RITEM_FILE    1
#define RITEM_REFRESH 2
#define RITEM_PROPS   3

// refresh for extra items
#define REFRESH_NONE     0
#define REFRESH_DESTRUCT 1
#define REFRESH_REMOVE   2
#define REFRESH_ALWAYS   3
#define REFRESH_INIT     4

// flag for blueprint item
#define	UNIQUE_OBJECT	1

#endif // __ROOM_ITEMS_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_ITEMS_H_PROTO__
#define __ROOM_ITEMS_H_PROTO__

// prototypes
varargs object AddItem(mixed filename, int refresh, mixed props);
void RemoveItem(mixed filename);

#endif // __ROOM_ITEMS_H_PROTO__

#endif	// NEED_PROTOYPES
