#ifndef _ROOM_
#define _ROOM_

#include "magic.h"
#include "doors.h"
#include "search.h"

/* entries in (special_)item array */
#define RITEM_FILE     0  /* items only */
#define RITEM_REFRESH  1  /* refreshtype */
#define RITEM_OBJECT   2  /* filename of (first) created object */

/* refreshflags for extra items */
#define REFRESH_NONE	 0  /* Don't refresh */

#define REFRESH_DESTRUCT   1  /* Refresh by recreationwhen destructed */
#define REFRESH_REMOVE	   2  /* Refresh by recreation when removed */
#define REFRESH_MOVE_HOME  4  /* Refresh by moving home */
#define REFRESH_HOME       (REFRESH_DESTRUCT|REFRESH_MOVE_HOME)
#define REFRESH_ALWAYS	   (REFRESH_DESTRUCT|REFRESH_REMOVE)
#define REFRESH_RESET	   8  /* Refresh by calling reset(1) */
#define REFRESH_PROPS	  16  /* Refresh by resetting props */
#define REFRESH_FUNC      32  /* Refresh by calling a function */

/* What the fields in the exits mapping mean */

#define EXIT_DEST   0	/* Either destination room, or destination function */
#define EXIT_OBJ    1	/* Funktion object: also serves as flag */
#define EXIT_DOOR   2	/* Associated door */
#define EXIT_HIDDEN 3	/* Flag if the exit is hidden */
#define EXIT_CHECK  4	/* Flag if the exit is to be checked */
#define EXIT_TARGET 5   /* In case of special exit the target room */

#define EXIT_COUNT  6   /* Number of fields in the mapping */

/* Argument two to an special exit function  */
#define EXIT_MOVE        0   /* really perform the action/move */
#define EXIT_QUERY_ONLY  1   /* return the target room|0 only */

/* What the fields in the doorvalue mapping mean */

#define DOOR_DIR    0	/* the directional command this door blocks */
#define DOOR_STATE  1	/* The state (LOCK_xxx) of the door */
#define DOOR_OBJECT 2	/* Returned by DoorInfo() */

#endif
