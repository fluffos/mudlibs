
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. A tall stand of reeds grows just to "
    "the southwest. The current flows quickly here."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading southeast.",
	       ({"stand","reeds"}) : "A thick forest of tall, strong reeds "
	         "blocks any possible sight of land."
  ]));
  set_exits(([
    "north":VPROOMS"river4h_3",
    "east":VPROOMS"river5_3h",
    "northwest":VPROOMS"river4_3",
    "southeast":VPROOMS"river5_4",
    "upriver":VPROOMS"river4_3",
    "downriver":VPROOMS"river5_4"
  ]));
  set_current_time(6);
}

