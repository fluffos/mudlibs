
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. To the north a large waterfall "
    "splashes down off a mountain, creating a fine mist all around. "
  );
  set_items(([ ({"water","river","spray"}) : "The river is all around you.",
    "waterfall" : "The water rolls off the mountain gently into the river.",
    "mountain" : "Brown stone that rises relatively quickly on the eastern "
      "bank. It doesn't look climbable.",
    "mist" : "It makes some things look a little hazy."
  ]));
  set_exits(([
    "west":VPROOMS"river1h_0",
    "southwest":VPROOMS"river1h_0h",
    "south":VPROOMS"river2_0h",
    "southeast":VPROOMS"river2h_0h",
    "downriver":VPROOMS"river2h_0h"
  ]));
  set_current_time(12);
}

