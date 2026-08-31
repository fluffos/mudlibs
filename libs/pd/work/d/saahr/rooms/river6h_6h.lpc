
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. There is more greenery visible on the "
    "east side of the river, but no way to get there. A small sandy area "
    "on the west bank is perfect for getting ashore. Some fish swim by "
    "underneath the water, and the river bed is clearly visible now."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southward.",
	       "greenery" : "Trees and shrubs.",
	       "fish" : "Average looking fish that dart away quickly.",
	       ({"bed","river bed"}) : "Sand peppered with small rocks and "
	         "a few plants."
  ]));
  set_exits(([
    "southwest":VPROOMS"p6_7",
    "north":VPROOMS"river6h_6",
    "southeast":VPROOMS"river7_7",
    "upriver":VPROOMS"river6h_6",
    "downriver":VPROOMS"river7_7"
  ]));
  set_current_time(8);
}

