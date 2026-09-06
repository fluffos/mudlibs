#ifndef _EXITSCONST_H_
#define _EXITSCONST_H_

#define EX_MAX_FLAG       5
#define EX_DEST_FLAG      0
#define EX_TYPE_FLAG      1
#define EX_BLOCKER_FLAG   2
#define EX_BLOCKTYPE_FLAG 3
#define EX_DESC_FLAG      4

#define INVERSE_EXITS ([ \
         "north"     : "south", \
         "northeast" : "southwest", \
         "east"      : "west", \
         "southeast" : "northwest", \
         "south"     : "north", \
         "southwest" : "northeast", \
         "west"      : "east", \
         "northwest" : "southeast", \
         "in"        : "out", \
         "out"       : "in", \
         "enter"     : "exit", \
         "exit"      : "enter", \
         "up"        : "down", \
         "down"      : "up" ])

// A macro to determine if the exit handle "h" is invalid.
#define BADEXIT(h) (intp(h) && (h) < 0)

#endif