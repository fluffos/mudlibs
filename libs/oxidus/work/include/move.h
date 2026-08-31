#ifndef __MOVE_H__
#define __MOVE_H__

#define MOVE_OK             0
#define MOVE_TOO_HEAVY      1
#define MOVE_NO_DEST        3
#define MOVE_NOT_ALLOWED    4
#define MOVE_DESTRUCTED     5
#define MOVE_ALREADY_THERE  6
#define MOVE_FIXED          7

#define MOVE_REASON ([ \
    MOVE_OK: "Ok", \
    MOVE_TOO_HEAVY: "Too heavy", \
    MOVE_NO_DEST: "No destination", \
    MOVE_NOT_ALLOWED: "Not allowed", \
    MOVE_DESTRUCTED: "Destructed", \
    MOVE_ALREADY_THERE: "Already there", \
    MOVE_FIXED: "Fixed in place", \
])

#endif // __MOVE_H__
