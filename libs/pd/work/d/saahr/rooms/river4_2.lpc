
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Above, a rope bridge hangs over the "
    "river. A bit of land can be seen eastward, but there's nowhere to "
    "go ashore here."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading south.",
               ({"land"}) : "Brown flashes between the "
                 "water spray seem to be solid land.",
	       "bridge" : "A bridge made of sturdy planks held together by "
	         "thick rope."
  ]));
  set_exits(([
    "west":VPROOMS"river3h_2",
    "southwest":VPROOMS"river3h_2h",
    "northwest":VPROOMS"river3h_1h",
    "south":VPROOMS"river4_2h",
    "upriver":VPROOMS"river3h_1h",
    "downriver":VPROOMS"river4_2h"
  ]));
  set_current_time(8);
}

