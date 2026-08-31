
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The spray of the river "
    "makes it hard to see much else, but several tree tops sprout "
    "up to the south."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading eastward.",
               ({"tree tops", "tops", "trees"}) : "Green leafy shafts just at "
	         "the edge of your vision."
  ]));
  set_exits(([
    "west":VPROOMS"river12_9h",
    "east":VPROOMS"river13_9h",
    "southwest":VPROOMS"river12_10",
    "upriver":VPROOMS"river12_9h",
    "downriver":VPROOMS"river13_9h"
  ]));
  set_current_time(6);
}

