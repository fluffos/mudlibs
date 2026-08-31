
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "The river here flows around a very large boulder that sticks up "
    "out of the water. The tops of a few water plants sway with the "
    "current, visible through the clear water."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "boulder" : "It is much larger than you, and the smooth "
	         "sides slope steeply up to a point.",
	       "plants" : "Deep green things that seem vaguely kelp-like. "
	         "The bottoms of the plants disappear into the deep river."
  ]));
  set_exits(([
    "west":VPROOMS"river4_3",
    "south":VPROOMS"river4h_3h",
    "northwest":VPROOMS"river4_2h",
    "southeast":VPROOMS"river5_3h",
    "upriver":VPROOMS"river4_2h",
    "downriver":VPROOMS"river5_3h"
  ]));
  set_current_time(6);
}

