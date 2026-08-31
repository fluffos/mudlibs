
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
    "north":VPROOMS"river8h_8",
    "southeast":VPROOMS"river9_9",
    "upriver":VPROOMS"river8h_8",
    "downriver":VPROOMS"river9_9"
  ]));
  set_current_time(8);
}

