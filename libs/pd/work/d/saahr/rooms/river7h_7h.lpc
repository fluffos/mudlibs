
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Trees can be see on either side of "
    "the river now. A leaf floats by gently on top of the water."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
	       "trees" : "Trees full of green leaves.",
	       "leaf" : "A single green leaf, unmarred."
  ]));
  set_exits(([
    "northwest":VPROOMS"river7_7",
    "east":VPROOMS"river8_7h",
    "upriver":VPROOMS"river7_7",
    "downriver":VPROOMS"river8_7h"
  ]));
  set_current_time(8);
}

