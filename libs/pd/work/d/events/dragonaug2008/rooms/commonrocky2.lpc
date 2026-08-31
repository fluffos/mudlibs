
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
    "sits unused, with a few piles of rubble strewn about. A clear "
    "path runs through the rubble where dragons have traveled recently. "
    "Many small lizards crawl up and down the rocky wall to the south."
  );
  set_items( ([
    "walls" : "Tall rocky walls that provide shade and protection.",
    "rubble" : "Piles of broken rocks that lie forgotten.",
    "path" : "The path leads southeast and north through the rubble piles.",
    "lizards" : "They dart quickly into cracks as you try to inspect them.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"common9",
    "northeast" : DRAG_ROOMS+"commonrocky1",
    "east" : DRAG_ROOMS+"commonrocky3",
    "southeast" : DRAG_ROOMS+"commonrocky4",
  ]) );
}

void reset() {
  int i = random(4);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

