
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Many apple trees can be seen on the "
    "south bank, and a few apples bob in the river. The current turns "
    "a little to the north here."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading northeast.",
	       ({ "trees", "apple trees" }) : "Tall trees with red fruit "
	         "hanging from the branches.",
	       "apples" : "Bright red apples that float along with the current.",
  ]));
  set_smell("default", "A strong smell of fruit comes from the south bank.");
  set_exits(([
    "west":VPROOMS"river14_9h",
    "northeast":VPROOMS"river15_9",
    "upriver":VPROOMS"river14_9h",
    "downriver":VPROOMS"river15_9"
  ]));
  set_current_time(8);
}

