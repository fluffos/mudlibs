
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. A long rope bridge hangs over the river "
    "just a bit farther south. Through the spray of the river, "
    "land can be seen faintly to the northeast."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "bridge" : "A sturdy-looking bridge with large planks to "
	         "walk on and thick rope holding it all together.",
               ({"land"}) : "Brown flashes between the "
                 "water spray seem to be solid land."
  ]));
  set_exits(([
//    "northeast":VPROOMS"p4_1",
    "west":VPROOMS"river3_1h",
    "south":VPROOMS"river3h_2",
    "southwest":VPROOMS"river3_2",
    "northwest":VPROOMS"river3_1",
    "southeast":VPROOMS"river4_2",
    "upriver":VPROOMS"river3_1",
    "downriver":VPROOMS"river4_2"
  ]));
  set_current_time(10);
}

