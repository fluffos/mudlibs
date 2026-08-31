
#include <std.h>
#include <saahr.h>

inherit LAKE_ROOM;

void create() {
  ::create();
  set_day_long(
    "The center of the lake is a clear expanse of water stretching in every "
    "direction. Blue waves bob slowly along the top of the lake. "
    "The sun shines down, creating streamers of light all along the water "
    "and revealing some small bubbles coming up from below."
  );
  set_night_long(
    "The center of the lake is a clear expanse of water stretching in every "
    "direction. Blue waves bob slowly along the top of the lake. "
    "The moons shine down, creating ribbons of light all along the water "
    "and revealing some small bubbles coming up from below."
  );
  set_items( (query_items() || ([])) + ([
    ({ "bubbles", "below" }) :
      "A slow, steady stream of bubbles rises from below the water.",
  ]) );
  set_exits( ([
    "north" : VPROOMS+"lake18_7",
    "east" : VPROOMS+"lake18h_7h",
    "southeast" : VPROOMS+"lake18h_8",
    "south" : VPROOMS+"lake18_8",
    "southwest" : VPROOMS+"lake17h_8",
    "west" : VPROOMS+"lake17h_7h",
    "down" : VPROOMS+"lake18_7h_below",
  ]) );
  add_invis_exit("down");
  add_exit_alias("down", "dive");
  add_exit_alias("down", "below");
}

