
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Trees line the northern bank, "
    "and a small bend of the river spreads to the south, dotted with "
    "branches, leaves, and other debris."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading eastward.",
               "trees" : "They are all along the northern bank of the river.",
	       ({"bank", "northern bank"}) : "Too steep to climb.",
	       ({"branches", "leaves", "debris"}) : "Small things floating "
	         "along to the south.",
  ]));
  set_exits(([
    "west":VPROOMS"river11h_9h",
    "east":VPROOMS"river12h_9h",
    "south":VPROOMS"river12_10",
    "upriver":VPROOMS"river11h_9h",
    "downriver":VPROOMS"river12h_9h"
  ]));
  set_current_time(8);
}

