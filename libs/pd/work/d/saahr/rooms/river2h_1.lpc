
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The middle of the river flows along "
    "gently. Through the spray of the river, "
    "some form appears in the air farther south."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "form" : "It's hard to see, but it looks pretty wide, "
	         "whatever it is."
  ]));
  set_exits(([
    "north":VPROOMS"river2h_0h",
    "east":VPROOMS"river3_1",
    "south":VPROOMS"river2h_1h",
    "west":VPROOMS"river2_1",
    "northwest":VPROOMS"river2_0h",
    "southeast":VPROOMS"river3_1h",
    "upriver":VPROOMS"river2_0h",
    "downriver":VPROOMS"river3_1h"
  ]));
  set_current_time(10);
}

