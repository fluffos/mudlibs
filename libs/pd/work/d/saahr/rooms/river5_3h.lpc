
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The river seems to be getting whiter "
    "and faster here. Submerged rocks and plants cause the water to churn "
    "almost violently."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "rocks" : "Large, slick rocks mostly below the surface.",
	       "plants" : "Some kind of river kelp or weed that dangles in "
	         "the current."
  ]));
  set_exits(([
    "west":VPROOMS"river4h_3h",
    "south":VPROOMS"river5_4",
    "northwest":VPROOMS"river4h_3",
    "southeast":VPROOMS"river5h_4",
    "upriver":VPROOMS"river4h_3",
    "downriver":VPROOMS"river5h_4"
  ]));
  set_current_time(6);
}

