
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. A rocky, impassable shore is to "
    "east. Southwards there seems to be a bridge over the water."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "shore" : "It's far too rocky and vertical to get out here.",
	       "bridge" : "A long bridge hangs in the air to the south."
  ]));
  set_exits(([
    "west":VPROOMS"river2h_1",
    "south":VPROOMS"river3_1h",
    "southwest":VPROOMS"river2h_1h",
    "northwest":VPROOMS"river2h_0h",
    "southeast":VPROOMS"river3h_1h",
    "upriver":VPROOMS"river2h_0h",
    "downriver":VPROOMS"river3h_1h"
  ]));
  set_current_time(10);
}

