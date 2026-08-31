
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The spray of the river "
    "makes it hard to see much else, but a bridge is visible "
    "just upriver."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading eastward.",
               ({"tree tops", "tops", "trees"}) : "Green leafy shafts just at "
	         "the edge of your vision.",
	       "bridge" : "A wooden bridge that spans the river. "
	         "It is to the west.",
  ]));
  set_exits(([
    "west":VPROOMS"river13h_9h",
    "east":VPROOMS"river14h_9h",
    "upriver":VPROOMS"river13h_9h",
    "downriver":VPROOMS"river14h_9h"
  ]));
  set_current_time(10);
}

