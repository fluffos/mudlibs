
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Rocks rise almost straight up "
    "from the water, leaving no shore. "
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "rocks" : "Large vertical cliffsides with a few boulders."
  ]));
  set_exits(([
    "west":VPROOMS"river2_0h",
    "south":VPROOMS"river2h_1",
    "southwest":VPROOMS"river2_1",
    "northwest":VPROOMS"river2_0",
    "southeast":VPROOMS"river3_1",
    "upriver":VPROOMS"river2_0",
    "downriver":VPROOMS"river3_1"
  ]));
  set_current_time(12);
}

