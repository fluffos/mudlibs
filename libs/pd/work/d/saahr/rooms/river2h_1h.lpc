
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. A bridge hangs over the river "
    "just a little farther along. The rocky slope to the west finally "
    "opens up a bit, and some shore can be seen to the southwest."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "bridge" : "It's a long and sturdy-looking rope bridge.",
	       ({"west","southwest","shore","slope"}) :
	         "A small but relatively smooth area appears among the rocks "
		 "where one could get out of the river."
  ]));
  set_exits(([
    "southwest":VPROOMS"p2_2",
    "north":VPROOMS"river2h_1",
    "east":VPROOMS"river3_1h",
    "northeast":VPROOMS"river3_1",
    "northwest":VPROOMS"river2_1",
    "southeast":VPROOMS"river3_2",
    "upriver":VPROOMS"river2_1",
    "downriver":VPROOMS"river3_2"
  ]));
  set_current_time(10);
}

