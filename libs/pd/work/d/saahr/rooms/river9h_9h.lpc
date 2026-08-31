
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Trees cover both banks of the river, "
    "and are especially thick to the north."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
	       "trees" : "Tall and thick with foliage.",
  ]));
  set_exits(([
    "northwest":VPROOMS"river9_9",
    "east":VPROOMS"river10_9h",
    "upriver":VPROOMS"river9_9",
    "downriver":VPROOMS"river10_9h"
  ]));
  set_current_time(8);
}

