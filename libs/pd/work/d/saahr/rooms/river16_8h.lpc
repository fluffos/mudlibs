
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "The river banks are far to the north and south here. "
    "A current from the west spreads out into a clear blue lake as "
    "it makes its way eastward."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading east.",
               ({"land", "banks", "river banks"}) :
	         "The river banks are too far away to see.",
               "lake" : "It is a clear expanse of water opening up to the east.",
  ]));
  set_exits(([
    "west":VPROOMS"river15h_8h",
    "east":VPROOMS"lake16h_8h",
    "upriver":VPROOMS"river15h_8h",
    "downriver":VPROOMS"lake16h_8h"
  ]));
  set_current_time(8);
}

