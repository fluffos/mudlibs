
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
    "Between the high mountain walls, this area begins to narrow. "
    "A wider open gathering area sits unused to the north, but here "
    "the path leads through a canyon. The walls are teeming with small "
    "lizards and insects crawling around."
  );
  set_items( ([
    "walls" : "Tall rocky walls that provide shade and protection.",
    "canyon" : "It leads eastward.",
    "lizards" : "They dart quickly into cracks as you try to inspect them.",
    "insects" : "Ants, beetles, and other crawlies looking for food.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"commonrocky3",
    "east" : DRAG_ROOMS+"lakepath1",
    "northwest" : DRAG_ROOMS+"commonrocky2",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

