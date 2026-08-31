
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The spray of the river "
    "makes it hard to see much else, but several tree tops sprout "
    "up to the south, and a wooden bridge can be seen just a bit "
    "further downriver."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading eastward.",
               ({"tree tops", "tops", "trees"}) : "Green leafy shafts just at "
	         "the edge of your vision.",
	       "bridge" : "A small sturdy wooden bridge.",
  ]));
  set_exits(([
    "west":VPROOMS"river12h_9h",
    "east":VPROOMS"river13h_9h",
    "upriver":VPROOMS"river12h_9h",
    "downriver":VPROOMS"river13h_9h"
  ]));
  set_current_time(6);
}

