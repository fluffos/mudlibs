
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "This small bend of the river is very calm, with a slow moving current. "
    "A large boulder pushes up just past the water, and many branches and "
    "leaves slowly swirl around it. To the south is a flat little area with "
    "willow trees all around it."
  );
  set_items(([ "current" : "The current seems to be heading northeast.",
	       "river" : "The river is all around you.",
	       "boulder" : "Round and grey, and wet from the river.",
	       ({ "branches", "leaves" }) : "The debris is slowly swirling "
	         "around the boulder, pushed by the current. Occaisonally "
		 "a piece is pulled out into the main part of the river.",
	       "trees" : "Willows droop all along the southern bank.",
  ]));
  set_exits(([
    "north":VPROOMS"river12_9h",
    "northeast":VPROOMS"river12h_9h",
    "south":VPROOMS"f12_11",
    "upriver":VPROOMS"river12_9h",
    "downriver":VPROOMS"river12h_9h"
  ]));
  set_current_time(20);
}

