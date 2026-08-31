
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Through the spray of the river, "
    "not much can be seen but flashes of brown and green on the banks. "
    "Twigs and other debris float by slowly."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading east.",
               ({"land"}) : "Brown flashes between the "
                 "water spray seem to be solid land."
  ]));
  set_exits(([
    "east":VPROOMS"river16_8h",
    "southwest":VPROOMS"river15_9",
    "upriver":VPROOMS"river15_9",
    "downriver":VPROOMS"river16_8h"
  ]));
  set_current_time(8);
}

