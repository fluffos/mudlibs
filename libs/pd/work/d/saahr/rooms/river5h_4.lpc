
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. Through the spray of the river, "
    "green land can be seen to the east. The current turns to the south "
    "in a sudden curve and goes much faster here."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading south.",
               ({"land"}) : "Green grass and trees are seen to the east."
  ]));
  set_exits(([
    "east":VPROOMS"f6_4",
    "west":VPROOMS"river5_4",
    "southwest":VPROOMS"river5_4h",
    "northwest":VPROOMS"river5_3h",
    "south":VPROOMS"river5h_4h",
    "upriver":VPROOMS"river5_3h",
    "downriver":VPROOMS"river5h_4h"
  ]));
  set_current_time(4);
}

