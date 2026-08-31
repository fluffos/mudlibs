
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Some fish swim by, occaisonally jumping "
    "up out of the water to catch insects. A large rock sits in the river "
    "here, sticking out of the water at an angle."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
	       "rock" : "It is gray-brown, solid, and has some markings on "
	         "one side.",
	       "markings" : "Some kind of carved figures."
  ]));
  set_exits(([
    "northwest":VPROOMS"river6h_6h",
    "southeast":VPROOMS"river7h_7h",
    "upriver":VPROOMS"river6h_6h",
    "downriver":VPROOMS"river7h_7h"
  ]));
  set_current_time(8);
}

