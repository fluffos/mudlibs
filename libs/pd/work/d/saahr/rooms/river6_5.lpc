
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_properties((["light":1]));
  set_long(
    "Water splashes all around you. Far above, the bottom of a bridge "
    "can be seen. Through the spray of the river, land can be seen faintly to "
    "the east and west. The current flows quickly here in the middle of the river."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
               ({"east","west","land"}) : "Brown flashes between the "
                 "water spray seem to be solid land.",
               ({"bridge","above"}) : "A gaping hole is visible in the bridge."
  ]));
  set_exits(([
    "northwest":VPROOMS"river5h_4h",
    "south":VPROOMS"river6_5h",
    "upriver":VPROOMS"river5h_4h",
    "downriver":VPROOMS"river6_5h"
  ]));
  set_current_time(4);
}

