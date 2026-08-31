
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The river flows through a narrow "
    "channel just to the east. A vertical rock wall diverts the current "
    "in that direction. There appears to be a bridge at the top."
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
               "current" : "The current seems to be heading east.",
	       "channel" : "A narrow area that causes the current to speed up",
	       ({"rock","wall","rock wall"}) : "It's just straight, flat rock "
	         "that is impossible to grab.",
	       "bridge" : "A rope bridge. It's hard to see much of it from here."
  ]));
  set_exits(([
    "northeast":VPROOMS"river5h_4",
    "north":VPROOMS"river5_4",
    "east":VPROOMS"river5h_4h",
    "upriver":VPROOMS"river5_4",
    "downriver":VPROOMS"river5h_4h"
  ]));
  set_current_time(4);
}

