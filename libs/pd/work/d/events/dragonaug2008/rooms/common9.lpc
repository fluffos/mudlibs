
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
    "Between the mountain peaks and walls, this open area is shaded "
    "and perfect for large gatherings. Some burn marks cover the ground, "
    "creating a sinister atmosphere. Broken rocks lie all around."
  );
  set_items( ([
    "peaks" : "They rise up against the sky.",
    "walls" : "Tall rocky walls that provide shade and protection.",
    "marks" : "Charred areas of rock.",
    "rocks" : "Many have been crushed and lie as a heap of pebbles; "
      "some have visible claw marks.",
  ]) );
  set_smell("default", "A light scent of charred earth.");
  set_exits( ([
    "north" : DRAG_ROOMS+"common6",
    "east" : DRAG_ROOMS+"commonrocky1",
    "southeast" : DRAG_ROOMS+"commonrocky3",
    "south" : DRAG_ROOMS+"commonrocky2",
    "west" : DRAG_ROOMS+"common8",
    "northwest" : DRAG_ROOMS+"common5",
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

