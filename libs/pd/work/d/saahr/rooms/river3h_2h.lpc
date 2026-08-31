
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Through the spray of the river, "
    "a bridge can be seen just to the north. The current flows "
    "quickly around some large, smooth rocks."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "bridge" : "A sturdy-looking rope bridge.",
	       "rocks" : "They protrude only a little from the water, "
	         "which keeps them clean and smooth."
  ]));
  set_exits(([
    "north":VPROOMS"river3h_2",
    "east":VPROOMS"river4_2h",
    "northeast":VPROOMS"river4_2",
    "northwest":VPROOMS"river3_2",
    "southeast":VPROOMS"river4_3",
    "upriver":VPROOMS"river3_2",
    "downriver":VPROOMS"river4_3"
  ]));
  set_current_time(8);
}

