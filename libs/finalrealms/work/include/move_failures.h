/*
 * Return codes you may get from ob->move(destination)
 */

/* The object was moved ok */
#define MOVE_OK 0

/* The destination object is not a container. */
#define MOVE_INVALID_DEST 1

/* The argument passed as destination is neither string nor object */
#define MOVE_BAD_DEST 2

/* The argument passed as destination was a file that could not be loaded */
#define MOVE_UNLOADABLE_DEST 3

/* The object is not gettable by the destination object.  */
#define MOVE_NOT_GETTABLE 4

/* The object may not be removed from its current environment. */
#define MOVE_NOT_DROPPABLE 5

/* The object could not be moved, since removing it would unbalance
 * its current environment.
 */
#define MOVE_TOO_HEAVY_FOR_SOURCE 6

/* The object could not be moved since adding it to the destination
 * object would unbalance the destination.
 */
#define MOVE_TOO_HEAVY_FOR_DEST 7

/* The object's current environment is a closed container */
#define MOVE_CLOSED_SOURCE 8

/* The destination object is a closed container */
#define MOVE_CLOSED_DEST 9

/* DO NOT USE THESE!
 * Supplied for backwards compatibility ONLY 
 */
#define MOVE_EMPTY_DEST   1
#define MOVE_NO_GET       4
#define MOVE_NO_DROP      5
#define MOVE_TOO_HEAVY    7
#define MOVE_TOO_BIG      7

