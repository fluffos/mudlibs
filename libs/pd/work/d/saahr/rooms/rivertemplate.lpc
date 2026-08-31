
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Through the spray of the river, "
    "land can be seen faintly to the south."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
               ({"land"}) : "Brown flashes between the "
                 "water spray seem to be solid land."
  ]));
  set_exits(([
    "west":VPROOMS"p5_5",
    "east":VPROOMS"f7_5",
    "northwest":VPROOMS"river5h_4h",
    "south":VPROOMS"river6_5h",
    "upriver":VPROOMS"river5h_4h",
    "downriver":VPROOMS"river6_5h"
  ]));
  set_current_time(4);
}

