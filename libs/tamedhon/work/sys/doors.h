// SilberLand MUDlib
//
// sys/doors.h -- door constants
//
// $Date$
/* $Revision$
 * $Log$
 */

#ifndef __DOORS__H_
#define __DOORS__H_

/*
 * definition of some door constants used when writing rooms.
 */

/* What the fields in the doorvalue array mean */
#define DOOR_DEST 0	/* the destination room filename */
#define DOOR_SHORT 1	/* the short name of the door (eg. green door) */
#define DOOR_LONG 2	/* long description. Should contain all newlines */
#define DOOR_KEY 3	/* id key must have to open door, or 0 for no lock */
#define DOOR_STATUS 4	/* The state of the door. See defines below */
#define DOOR_STATUS_OPEN 0
#define DOOR_STATUS_CLOSED 1
#define DOOR_STATUS_LOCKED 2

#endif

