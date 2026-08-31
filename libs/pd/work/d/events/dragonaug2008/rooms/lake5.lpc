
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
    "The lake here is easily disturbed by the waves of swimmers. The rock "
    "wall to the east is uneven, creating a small pool of shallow water. "
    "The shallow area is surrounded by boulders, and drops off quickly into "
    "the rest of the lake."
  );
  set_items( ([
    "lake" : "The lake extends to the west.",
    "wall" : "A vertical wall of rock that encloses the lake.",
    "pool" : "The bottom of it is sandy, but there seems to be nothing "
      "special about it.",
    "boulders" : "Jagged boulders that are just partially submerged.",
  ]) );
  set_exits( ([
    "southeast" : DRAG_ROOMS+"lake8",
    "west" : DRAG_ROOMS+"bluelake",
    "northwest" : DRAG_ROOMS+"lake3",
  ]) );
}

void reset() {
  int i = random(5);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }
}

