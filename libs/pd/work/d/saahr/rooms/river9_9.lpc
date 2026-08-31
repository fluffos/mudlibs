
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Trees cover both banks of the river, "
    "and are especially thick to the east."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
	       "trees" : "Tall and thick with foliage.",
  ]));
  set_exits(([
    "northwest":VPROOMS"river8h_8h",
    "southeast":VPROOMS"river9h_9h",
    "upriver":VPROOMS"river8h_8h",
    "downriver":VPROOMS"river9h_9h"
  ]));
  set_current_time(8);
}

