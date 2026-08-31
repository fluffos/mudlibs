
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Through the spray of the river, "
    "land can be seen faintly to the south. A few trees with red fruit "
    "sit along the southern bank."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
               ({"land"}) : "Brown flashes between the "
                 "water spray seem to be solid land.",
	       "trees" : "Tall trees that spread south from the bank.",
	       "fruit" : "Probably apples.",
  ]));
  set_exits(([
    "southwest":VPROOMS"river14h_9h",
    "northeast":VPROOMS"river15h_8h",
    "upriver":VPROOMS"river14h_9h",
    "downriver":VPROOMS"river15h_8h"
  ]));
  set_current_time(4);
}

