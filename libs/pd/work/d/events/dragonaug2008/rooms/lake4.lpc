
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1, "water" : 1,
  ]) );
  set_short("a lake");
  set_long(
    "The water laps silently against the western wall. Even at the edge, "
    "the lake is very deep and the bottom cannot be seen. A bit of plant "
    "life seems to have taken hold on the wall, just under the surface."
  );
  set_items( ([
    "water" : "It is all around you.",
    ({ "plant", "plant life" }) : "A trailing bit of green that is anchored "
      "to the rock wall. The top sits just on the surface of the lake.",
  ]) );
  set_exits( ([
    "east" : DRAG_ROOMS+"bluelake",
    "southeast" : DRAG_ROOMS+"lake6",
    "northwest" : DRAG_ROOMS+"lake1",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }
}

