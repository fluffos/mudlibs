
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1,
  ]) );
  set_short("a mountain");
  set_long(
    "Beneath the shade of the mountain walls, this gathering spot "
    "sits unused. Small bits of bones lie near the eastern wall. "
    "Many small lizards crawl up and down the wall, and birds fly "
    "through the area."
  );
  set_items( ([
    "walls" : "Tall rocky walls that provide shade and protection.",
    "bones" : "They seem to be from some kind of deer or goat.",
    "lizards" : "They dart quickly into cracks as you try to inspect them.",
    "birds" : "Blue and red birds that fly through without stopping.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"commonrocky1",
    "south" : DRAG_ROOMS+"commonrocky4",
    "west" : DRAG_ROOMS+"commonrocky2",
    "northwest" : DRAG_ROOMS+"common9",
  ]) );
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

