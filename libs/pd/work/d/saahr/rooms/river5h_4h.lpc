
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The river runs through a narrow "
    "channel to the southeast. A bridge hangs over it. The river bed is "
    "hard to see here due to the fast current."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "channel" : "A narrow area of the river with raised rock sides.",
	       "bridge" : "A rickety looking rope bridge.",
	       ({"bed", "river bed"}) : "It's obscured by the current."
  ]));
  set_exits(([
    "west":VPROOMS"river5_4h",
    "north":VPROOMS"river5h_4",
    "northwest":VPROOMS"river5_4",
    "southeast":VPROOMS"river6_5",
    "upriver":VPROOMS"river5_4",
    "downriver":VPROOMS"river6_5"
  ]));
  set_current_time(4);
}

