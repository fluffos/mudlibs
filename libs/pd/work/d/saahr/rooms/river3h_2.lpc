
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. A rope bridge hangs in the air above. "
    +(query_night()?"Moon":"Sun")+"light filters down through the boards."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "bridge" : "It is made of large sturdy planks with a thick "
	         "rope holding it together.",
	       "sunlight" : "The sunlight is blindingly bright!",
	       "moonlight" : "Soft and illuminating."
  ]));
  set_exits(([
    "north":VPROOMS"river3h_1h",
    "south":VPROOMS"river3h_2h",
    "west":VPROOMS"river3_2",
    "east":VPROOMS"river4_2",
    "northwest":VPROOMS"river3_1h",
    "southeast":VPROOMS"river4_2h",
    "upriver":VPROOMS"river3_1h",
    "downriver":VPROOMS"river4_2h"
  ]));
  set_current_time(10);
}

