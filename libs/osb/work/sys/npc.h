#ifndef _NPC_H_
#define _NPC_H_ 1

#include "living.h"


//-----------------------------------------------------------------------
// Modes for Drop()

#define PUTGET_SILENT      1   // Issue no messages
#define PUTGET_FULL    (1<<1)  // Return full result field.
#define PUTGET_REALLY  (1<<2)  // Handle wielded equipment as well.

// Data fields of the full result of Drop() and co

#define PUTGET_OK        0  // Objects being dropped.
#define PUTGET_NODROP    1  // Objects which have NO_DROP defined.
#define PUTGET_NOMOVE    2  // Objects which don't move at all.
#define PUTGET_NOLEAVE   3  // Objects which couldn't leave their place.
#define PUTGET_TOOHEAVY  4  // Objects which were too heavy for destination

#define PUTGET_COUNT     5  // Number of full result fields

// Data fields of the full result of EquipLayoff()

#define EQUIP_OK        0  // Objects being dropped.
#define EQUIP_NOEQUIP   1  // Objects which are of the wrong type.
#define EQUIP_FAIL      2  // Objects which failed to response.

#define EQUIP_COUNT     3  // Number of full result fields

//-----------------------------------------------------------------------
// Modes for the sensing functions.

#define SENSE_MOVE       1  // LookRoom(): called from move().
#define SENSE_IMPL       1  // Sense(): implode result.
#define SENSE_SILENT (1<<1) // Issue no messages

//-----------------------------------------------------------------------
// Modes for Inventory()

#define INV_FLAT   1  // List just the top inventory.
#define INV_LONG   2  // Don't fold items of matching description.
#define INV_NARROW 4  // Format the strings for 38 char linesize

#endif
