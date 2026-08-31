
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Directly above, the boards that make up "
    "a wooden bridge block out most of the light. The river spray is "
    "very light here and the water flows slowly.",
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading eastward.",
               ({"tree tops", "tops", "trees"}) : "Green leafy shafts just at "
	         "the edge of your vision.",
	       ({ "boards", "bridge" }) :
	         "Thick boards to walk over the river. "
		 "The bridge is out of reach.",
  ]));
  set_exits(([
    "west":VPROOMS"river13_9h",
    "east":VPROOMS"river14_9h",
    "upriver":VPROOMS"river13_9h",
    "downriver":VPROOMS"river14_9h"
  ]));
  set_current_time(12);
}

