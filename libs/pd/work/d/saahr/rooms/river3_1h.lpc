
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The bridge to the south is almost directly "
    "overhead now. A bit of rock can be glanced on each shore, but it would "
    "take some swimming to get there."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
               ({"rock","shore"}) : "The rocky shores are east and west.",
               "bridge" : "A sturdy-looking rope bridge."
  ]));
  set_exits(([
    "north":VPROOMS"river3_1",
    "east":VPROOMS"river3h_1h",
    "south":VPROOMS"river3_2",
    "west":VPROOMS"river2h_1h",
    "northwest":VPROOMS"river2h_1",
    "southeast":VPROOMS"river3h_2h",
    "upriver":VPROOMS"river2h_1",
    "downriver":VPROOMS"river3h_2h"
  ]));
  set_current_time(8);
}

