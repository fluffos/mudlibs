
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The rocky slope to the west begins "
    "to come closer to the water."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "slope" : "The rocky wall is starting to slope down towards "
	         "the water."
  ]));
  set_exits(([
    "north":VPROOMS"river2_0h",
    "east":VPROOMS"river2h_1",
    "northeast":VPROOMS"river2h_0h",
    "northwest":VPROOMS"river1h_0h",
    "southeast":VPROOMS"river2h_1h",
    "upriver":VPROOMS"river1h_0h",
    "downriver":VPROOMS"river2h_1h"
  ]));
  set_current_time(10);
}

