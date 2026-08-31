
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Some plains grass grows on the western "
    "bank here, but tall reeds and thorny bushes make the bank impassable. "
    "The river flows quickly despite the plants."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       "grass" : "Stiff, light green grass with only a hint of the "
	         "yellow that covers most of the plain.",
	       "bank" : "A small area with less rocks. It is almost entirely "
	         "covered by reeds and thorn bushes.",
	       "reeds" : "Slender, thick plants that grow taller than a human.",
	       "bushes" : "They have jagged dark green leaves and sharp thorns "
	         "all over.",
	       "plants" : "Grasses, reeds, and thorn bushes cover the bank."
  ]));
  set_exits(([
    "north":VPROOMS"river4_2h",
    "east":VPROOMS"river4h_3",
    "northwest":VPROOMS"river3h_2h",
    "southeast":VPROOMS"river4h_3h",
    "upriver":VPROOMS"river3h_2h",
    "downriver":VPROOMS"river4h_3h"
  ]));
  set_current_time(8);
}

