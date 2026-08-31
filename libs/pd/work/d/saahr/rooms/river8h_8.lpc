
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Leaves float by on the current. "
    "A small fish hops out of the water and darts back down."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
	       "leaves" : "Green leaves floating lazily.",
	       "fish" : "It is gone too quickly to get a good look at it.",
  ]));
  set_exits(([
    "east":VPROOMS"town9_8",
    "northwest":VPROOMS"river8_7h",
    "south":VPROOMS"river8h_8h",
    "upriver":VPROOMS"river8_7h",
    "downriver":VPROOMS"river8h_8h"
  ]));
  set_current_time(4);
}

