#ifndef _sys_orientation_h
#define _sys_orientation_h

/* long versions of the directions */
#define O_NORTH                 "north"
#define O_NORTH_NORTH_EAST      "northnortheast"
#define O_NORTH_EAST            "northeast"
#define O_EAST_NORTH_EAST       "eastnortheast"
#define O_EAST                  "east"
#define O_EAST_SOUTH_EAST       "eastsoutheast"
#define O_SOUTH_EAST            "southeast"
#define O_SOUTH_SOUTH_EAST      "southsoutheast"
#define O_SOUTH                 "south"
#define O_SOUTH_SOUTH_WEST      "southsouthwest"
#define O_SOUTH_WEST            "southwest"
#define O_WEST_SOUTH_WEST       "westsouthwest"
#define O_WEST                  "west"
#define O_WEST_NORTH_WEST       "westnorthwest"
#define O_NORTH_WEST            "northwest"
#define O_NORTH_NORTH_WEST      "northnorthwest"

#define O_NOWHERE               "nowhere"

#define O_UP                    "up"
#define O_DOWN                  "down"

#define O_IN                    "in"
#define O_OUT                   "out"

/* short versions of the directions */
#define OS_NORTH                 "n"
#define OS_NORTH_NORTH_EAST      "nne"
#define OS_NORTH_EAST            "ne"
#define OS_EAST_NORTH_EAST       "ene"
#define OS_EAST                  "e"
#define OS_EAST_SOUTH_EAST       "ese"
#define OS_SOUTH_EAST            "se"
#define OS_SOUTH_SOUTH_EAST      "sse"
#define OS_SOUTH                 "s"
#define OS_SOUTH_SOUTH_WEST      "ssw"
#define OS_SOUTH_WEST            "sw"
#define OS_WEST_SOUTH_WEST       "wsw"
#define OS_WEST                  "w"
#define OS_WEST_NORTH_WEST       "wnw"
#define OS_NORTH_WEST            "nw"
#define OS_NORTH_NORTH_WEST      "nnw"

#define OS_NOWHERE               "h" /* for 'here' */

#define OS_UP                    "u"
#define OS_DOWN                  "d"

#define OS_IN                    "in"
#define OS_OUT                   "out"

/* relative-turn-modes */
#define OM_LEFT         (-1)
#define OM_AHEAD        0
#define OM_RIGHT        1
#define OM_REVERSE      2

#endif /* _sys_orientation_h */
