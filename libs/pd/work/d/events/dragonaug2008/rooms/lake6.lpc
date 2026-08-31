
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
    "The lake is very cold and very calm. A rock wall just to the west "
    "encloses it and quickly breaks up any waves. Most of the lake lies to "
    "the north, and solid ground is just a quick swim away."
  );
  set_items( ([
    "lake" : "The lake is a large body of water nestled in the mountains.",
    "wall" : "A vertical wall of rock.",
    "ground" : "The shore is to the southeast.",
  ]) );
  set_touch("default", "There is nothing to feel here except the water, "
    "which is quite cold and, of course, wet.");
  set_exits( ([
    "north" : DRAG_ROOMS+"bluelake",
    "east" : DRAG_ROOMS+"lake7",
    "southeast" : DRAG_ROOMS+"lakeside1",
    "northwest" : DRAG_ROOMS+"lake4",
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

