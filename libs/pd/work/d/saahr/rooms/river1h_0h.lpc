
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The river is fairly shallow here, "
    "though reaching the bottom would still require some diving. "
    "A high wall of rock takes up the entire western bank. "
    "The current flows slowly to the southeast. "
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
    "bottom" : "Through the calm, clear water you can see a sandy river bed "
      "decorated by various smooth stones and a few plants.",
    ({"wall","rock","bank","western bank"}) : "Rock rises up directly from "
      "the river, leaving no place to get ashore.",
  ]));
  set_exits(([
    "north":VPROOMS"river1h_0",
    "east":VPROOMS"river2_0h",
    "northeast":VPROOMS"river2_0",
    "northwest":VPROOMS"river1_0",
    "southeast":VPROOMS"river2_1",
    "upriver":VPROOMS"river1_0",
    "downriver":VPROOMS"river2_1"
  ]));
  set_current_time(12);
}

