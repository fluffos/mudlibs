
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. A patch of flat dry land on the north bank "
    "looks like a viable place to get out of the river. Trees cover both banks."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
               "land" : "Flat dirt.",
               "trees" : "Tall green trees with thick branches and trunks."
  ]));
  set_exits(([
    "north":VPROOMS"f8_7",
    "west":VPROOMS"river7h_7h",
    "southeast":VPROOMS"river8h_8",
    "upriver":VPROOMS"river7h_7h",
    "downriver":VPROOMS"river8h_8"
  ]));
  set_current_time(6);
}

