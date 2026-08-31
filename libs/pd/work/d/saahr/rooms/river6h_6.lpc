
#include <std.h>
#include <saahr.h>

inherit RIVER_ROOM;

void create() {
  ::create();
  set_long(
    "Water splashes all around you. The narrow channel opens back up "
    "here, widening and slowing the river. Some land can be seen "
    "faintly to the west. Some trees are visible on "
    "the eastern bank. A bridge can be seen towards the northwest."
  );
  set_items(([
    ({"water","river","spray"}) : "The river is all around you.",
    ({"west","land"}) : "Brown flashes between the "
      "water spray seem to be solid land.",
    ({"trees","bank","eastern bank"}) : "Blobs of green to the east.",
    ({"bridge","northwest"}) : "A rickity looking bridge hangs over "
      "the river to the northwest."
  ]));
  set_exits(([
    "west":VPROOMS"p6_6",
    "northwest":VPROOMS"river6_5h",
    "south":VPROOMS"river6h_6h",
    "upriver":VPROOMS"river6_5h",
    "downriver":VPROOMS"river6h_6h"
  ]));
  set_current_time(8);
}

