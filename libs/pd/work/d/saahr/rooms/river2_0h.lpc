
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The middle of the river moves a bit more "
    "quickly. Rock can be seen rising from the banks on either side of the river."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
    "middle" : "There's nothing but water all around.",
    ({"rock","banks"}) : "Rock rises up from the banks. It's hard to tell "
      "if there's anywhere to get ashore or not."
  ]));
  set_exits(([
    "north":VPROOMS"river2_0",
    "east":VPROOMS"river2h_0h",
    "south":VPROOMS"river2_1",
    "west":VPROOMS"river1h_0h",
    "northwest":VPROOMS"river1h_0",
    "southeast":VPROOMS"river2h_1",
    "upriver":VPROOMS"river1h_0",
    "downriver":VPROOMS"river2h_1"
  ]));
  set_current_time(10);
}

