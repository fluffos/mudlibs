
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_properties((["light":1]));
  set_long(
    "Water splashes all around you. Above, a rope bridge sways gently in the "
    "breeze. It meets land just to the west, but there's nowhere to get ashore "
    "here."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "bridge" : "The bridge has large planks to walk on. "
	         "It is held together by thick rope."
  ]));
  set_exits(([
    "east":VPROOMS"river3h_2",
    "north":VPROOMS"river3_1h",
    "northeast":VPROOMS"river3h_1h",
    "northwest":VPROOMS"river2h_1h",
    "southeast":VPROOMS"river3h_2h",
    "upriver":VPROOMS"river2h_1h",
    "downriver":VPROOMS"river3h_2h"
  ]));
  set_current_time(10);
}

