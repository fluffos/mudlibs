
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Through the river spray, a bit of green "
    "can be seen eastwards. Up an impossibly steep bank to the west, some "
    "yellowish grasses grow and hang down. The river swirls white and blue "
    "all around."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       ({"green","east","eastwards"}) : "Just a quick flash "
	         "of greenery.",
	       ({"west","bank","grasses"}) : "Dry, brittle grasses droop "
	         "down over the top of the sloping bank, but they're still "
		 "far out of reach."
  ]));
  set_exits(([
    "north":VPROOMS"river5_3h",
    "east":VPROOMS"river5h_4",
    "south":VPROOMS"river5_4h",
    "northwest":VPROOMS"river4h_3h",
    "southeast":VPROOMS"river5h_4h",
    "upriver":VPROOMS"river4h_3h",
    "downriver":VPROOMS"river5h_4h"
  ]));
  set_current_time(6);
}

