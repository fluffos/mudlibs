
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The bank to the east is far too rough and "
    "overgrown to go ashore here. Just north, a bridge hangs over the river."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
               "bank" : "Sharp rocks and tall reedy plants cover the bank.",
               "bridge" : "A rope bridge."
  ]));
  set_exits(([
    "west":VPROOMS"river3h_2h",
    "north":VPROOMS"river4_2",
    "south":VPROOMS"river4_3",
    "northwest":VPROOMS"river3h_2",
    "southeast":VPROOMS"river4h_3",
    "upriver":VPROOMS"river3h_2",
    "downriver":VPROOMS"river4h_3"
  ]));
  set_current_time(8);
}

