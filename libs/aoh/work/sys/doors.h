#ifndef _DOORS_
#define _DOORS_

#include "lock.h"

#ifndef P_DIRECTION

#define P_CHECKDOOR  "CheckDoor"
#define P_DIRECTION  "Direction"
#define P_DOORCODE   "DoorCode"
#define P_OTHERROOM  "OtherRoom"
#define P_DOORROOM   "DoorRoom"
#define P_HIDEDOOR   "HideDoor"
#define P_HIDEEXIT   "HideExit"

#define P_CHECKOBJ    "CheckObj" // /obj/door
#define P_CHECKNOTIFY "CheckNotify" // /obj/door

#endif

/* InterDoorProtocol */
#define IDP_NEWSTATE 1  /* Door state is changed remotely */
#define IDP_DESTRUCT 2  /* Door is destructed */
#define IDP_VANISH   3  /* Door is removed from its place */
#define IDP_SAY      4  /* Say a message */
#define IDP_SHOW     5  /* Show a message */
#define IDP_EXTRA    6  /* Add your own messages here */

// Hiding doors from the Obvious Doors list.

#define HIDE_NOT     0  // Door is always listed
#define HIDE_OPEN    1  // Door is not listed if open
#define HIDE_CLOSED  2  // Door is not listed if closed.
#define HIDE_ALWAYS  (HIDE_CLOSED|HIDE_OPEN)
#define HIDE_BOTH    4  // Also modify the remote door if existing.

// Checking door commands.

#ifndef DACT_NOT

#define DACT_NOT    0  // Door activity is not checked.
#define DACT_HIDE   1  // Door activity is checked if hidden.
#define DACT_CHECK  2  // Door activity is checked.
#define DACT_UNHIDE (DACT_HIDE|DACT_CHECK)
                       // Door activity is checked if not hidden.
#define DACT_BOTH   4  // Also modify the remote door if existing.

#endif

#endif
