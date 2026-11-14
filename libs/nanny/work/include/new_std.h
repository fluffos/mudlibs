/*  std.h - the NEW IMPROVED and ALMOST COMPATIBLE version!
 *	But it is still obsolete, so don't use it for new rooms.
 *	Inherit /room/room instead, or include room.h.
 *  Latest change of this file: May 20, 1992, by Padrone
 */

/*  Backwards compatibility:
 *  This is almost just as the old ONE_EXIT, TWO_EXIT etc from "std.h".
 *  It works if you use EXTRA_INIT, EXTRA_RESET and EXTRA_LONG,
 *  but it may not if you use EXTRA_MOVE1, EXTRA_MOVE2 etc.
 *  It's probably better to re-write the rooms.
 *  This takes more memory than the old std.h.
 */

#include "inorout.h"
inherit "room/room";

#define EXTRA_INIT
#define EXTRA_RESET
#define EXTRA_LONG
#define EXTRA_MOVE1
#define EXTRA_MOVE2
#define EXTRA_MOVE3
#define EXTRA_MOVE4

#define ONE_EXIT(Dest1, Dir1, Short, Long, Light) \
reset(arg) {	\
    EXTRA_RESET	\
    dest_dir = ({ Dest1, Dir1 });	\
    blocked_exits = ({ "check_extra_move1" });	\
    short_desc = Short;	\
    long_desc = Long;	\
    set_light(Light);	\
}	\
init() { ::init(); EXTRA_INIT } \
long(str) { if (set_light(0)) { EXTRA_LONG } ::long(str); } \
check_extra_move1() { EXTRA_MOVE1 return 0; }

#define TWO_EXIT(Dest1, Dir1, Dest2, Dir2, Short, Long, Light) \
reset(arg) {	\
    EXTRA_RESET	\
    dest_dir = ({ Dest1, Dir1, Dest2, Dir2 });	\
    blocked_exits = ({ "check_extra_move1", "check_extra_move2" });	\
    short_desc = Short;	\
    long_desc = Long;	\
    set_light(Light);	\
}	\
init() { ::init(); EXTRA_INIT } \
long(str) { if (set_light(0)) { EXTRA_LONG } ::long(str); }	\
check_extra_move1() { EXTRA_MOVE1 return 0; }	\
check_extra_move2() { EXTRA_MOVE2 return 0; }

#define THREE_EXIT(Dest1, Dir1, Dest2, Dir2, Dest3, Dir3, Short, Long, Light) \
reset(arg) {	\
    EXTRA_RESET	\
    dest_dir = ({ Dest1, Dir1, Dest2, Dir2, Dest3, Dir3  });	\
    blocked_exits = ({ "check_extra_move1", "check_extra_move2", "check_extra_move3" });	\
    short_desc = Short;	\
    long_desc = Long;	\
    set_light(Light);	\
}	\
init() { ::init(); EXTRA_INIT } \
long(str) { if (set_light(0)) { EXTRA_LONG } ::long(str); }	\
check_extra_move1() { EXTRA_MOVE1 return 0; }	\
check_extra_move2() { EXTRA_MOVE2 return 0; }	\
check_extra_move3() { EXTRA_MOVE3 return 0; }

#define FOUR_EXIT(Dest1, Dir1, Dest2, Dir2, Dest3, Dir3, Dest4, Dir4, Short, Long, Light) \
reset(arg) {	\
    EXTRA_RESET	\
    dest_dir = ({ Dest1, Dir1, Dest2, Dir2, Dest3, Dir3, Dest4, Dir4 });	\
    blocked_exits = ({ "check_extra_move1", "check_extra_move2",	\
		       "check_extra_move3", "check_extra_move4" });	\
    short_desc = Short;	\
    long_desc = Long;	\
    set_light(Light);	\
}	\
init() { ::init(); EXTRA_INIT } \
long(str) { if (set_light(0)) { EXTRA_LONG } ::long(str); }	\
check_extra_move1() { EXTRA_MOVE1 return 0; }	\
check_extra_move2() { EXTRA_MOVE2 return 0; }	\
check_extra_move3() { EXTRA_MOVE3 return 0; }	\
check_extra_move4() { EXTRA_MOVE4 return 0; }
