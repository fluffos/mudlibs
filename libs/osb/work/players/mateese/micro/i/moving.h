#ifndef MOVING_H
#define MOVING_H 1

// Move methods

#define M_NORMAL   0  // normal move, with all checks.
#define M_GO       1  // a simple walk, MsgIn/MsgOut are used for messages.
#define M_TELEPORT 2  // teleport, MMsgIn/MMsgOut are used for messages.
#define M_PUT      3  // is like dropping to a special destination
#define M_DROP     4  // if the extra arg is !=0, we move silently
#define M_TAKE     5
#define M_GIVE     6  // is like M_TAKE and M_DROP in one move

// Object shall be destructed. This method is just used when the object
// will be destructed or selfdestructs and notifies its environment with
// destination = 0 and method = M_DESTRUCT.

#define M_DESTRUCT  7

// Move modifications

#define MM_NOCHECKS (1<<7)  // No checks are done.
#define MM_SILENT   (1<<6)  // Silent move, no messages.
#define MM_SPECIAL  (1<<5)  // Messages are provided by the caller.
#define MM_MULTI    (1<<4)  // This move is one of several in a row.

// The return values of the function move().

#define ME_NOT         0 // general == default if move() is not defined
#define ME_OK          1 // as already is now
#define ME_DESTRUCTED  2 // object was destructed while moving
#define ME_NO_LEAVE    3 // was not allowed to leave current env
#define ME_NO_ENTER    4 // entrance was denied entering for unknown reason
#define ME_TOO_HEAVY   5 // dest cannot carry us
#define ME_CAUGHT_ERR  6 // Caught error on move_object()
#define ME_NO_DROP     7 // object does not want to be dropped: TODO: needed?
#define ME_NO_TAKE     8 // object does not want to be picked up: TODO: needed?
#define ME_NO_GIVE     9 // object does not want to be given away: TODO: needed?

// A nicy: the value to return from prevent*() if there is no reason to
// prevent the move.

#define ME_NO_PREVENT  0

// Values for teleport forbid property

#define TPORT_OK    0
#define TPORT_IN    1
#define TPORT_OUT   2
#define TPORT_BOTH  (TPORT_IN | TPORT_OUT)

#endif
