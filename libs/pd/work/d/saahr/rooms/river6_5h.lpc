
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Through the spray of the river, "
    "land can be seen faintly to the south. Small rocks protrude out "
    "of the water."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               ({"south","land"}) : "Brown flashes between the "
                 "water spray seem to be solid land.",
	       ({"rocks","small rocks"}) : "A few rounded pieces of rock "
	         "which would be far too slippery to grab."
  ]));
  set_exits(([
    "south":VPROOMS"p6_6",
    "north":VPROOMS"river6_5",
    "southeast":VPROOMS"river6h_6",
    "upriver":VPROOMS"river6_5",
    "downriver":VPROOMS"river6h_6",
  ]));
  set_current_time(6);
}

