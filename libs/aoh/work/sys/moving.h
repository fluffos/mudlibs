/* -------------------------------------------------------------------------
 * sys/moving.h -- moveing related definitions
 *
 * Copyright (C) 1997,1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * CHANGES
 *  06/28/98 [Mica] added direction-defines
 */

#ifndef _MOVING_
#define _MOVING_

#define LR_DIRECTIONS ({ "forward", "forwardright", "right", "backleft", "back", "backright", "left", "forwardleft" })
#define COMPASS_DIRECTIONS ({ "north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest" })
#define OTHER_DIRECTIONS ({ "up", "down", "enter", "leave", "in", "out" })

#define M_SILENT     0  /* do a silent move but with all checks */
#define M_NOCHECK    1  /* don't do any checks just inform the environment */
#define M_GO         2  /* a simple walk */
#define M_TELEPORT   3  /* use MMsgIn/Out instead of MsgIn/Out */
#define M_SPECIAL    4  /* freely choosable message */

#define M_PUT        5
#define M_DROP       6  /* if the extra arg is !=0, we move silently */
#define M_GET        7
#define M_GIVE       8  /* is like M_DROP and M_GET in one move */

/* Object shall be destructed. This method is just used when the object
 * will be destructed or selfdestructs and notifies its environment with
 * destionation = 0 and mehtod = M_DESTRUCT.
 */
#define M_DESTRUCT   9


/* The return values of the function move().
 * All values except for ME_OK are error values and descripe the
 * the reason why the move failed.
 */
#define ME_NO_MOVE         0 /* general == default if move() is not defined */
#define ME_OK              1 /* as already is now */
#define ME_DESTRUCTED_SELF 2 /* object was destructed while moving */
#define ME_NO_LEAVE        3 /* was not allowed to leave current env */
#define ME_NO_ENTER        4 /* was denied entering for unknown reason */
#define ME_TOO_HEAVY       5 /* dest cannot carry us */
#define ME_CAUGHT_ERR      6 /* Caught error on move_object() */
#define ME_NO_DROP         7 /* object does not want to be dropped */
#define ME_NO_GET          8 /* object does not want to be picked up */
#define ME_NO_GIVE         9 /* object does not want to be given away */

/* The preventation functions prevent_*() return this value
 * instead ME_NO_MOVE but both values are equal so ME_NO_PREVENT
 * is just a formal thing.
 */
#define ME_NO_PREVENT      0 /* default if function is not defined */

#endif
