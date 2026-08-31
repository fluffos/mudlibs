
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The spray of the river "
    "makes it hard to see much else, but a few tree tops sprout "
    "up to the south."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading eastward.",
               ({"tree tops", "tops", "trees"}) : "Green leafy shafts just at "
	         "the edge of your vision."
  ]));
  set_exits(([
    "west":VPROOMS"river10_9h",
    "east":VPROOMS"river11_9h",
    "upriver":VPROOMS"river10_9h",
    "downriver":VPROOMS"river11_9h"
  ]));
  set_current_time(8);
}

