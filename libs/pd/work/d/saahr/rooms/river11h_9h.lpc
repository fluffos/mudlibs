
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Trees line the northern bank and "
    "a few sprout up to the south. The spray of the river "
    "makes it hard to see much else."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading eastward.",
               ({"tree tops", "tops", "trees"}) : "Trees line the northern "
	         "bank and a some tree tops sit at "
	         "the edge of your vision to the south.",
	       ({"bank","northern bank"}) : "It's much too steep to "
	         "climb out of the river here.",
  ]));
  set_exits(([
    "west":VPROOMS"river11_9h",
    "east":VPROOMS"river12_9h",
    "upriver":VPROOMS"river11_9h",
    "downriver":VPROOMS"river12_9h"
  ]));
  set_current_time(8);
}

