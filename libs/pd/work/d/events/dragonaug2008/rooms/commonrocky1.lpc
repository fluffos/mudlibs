
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
    "sits full of rubble. Broken rocks lie all around in heaps. "
    "Claw marks are visible on the wall to the east, and scorch "
    "marks cover the ground."
  );
  set_items( ([
    "walls" : "Tall rocky walls that provide shade and protection.",
    ({ "rubble", "rocks" }) : "The rocks have been crushed into heaps "
      "of rubble that lie all around.",
    "claw marks" : "A set of deep cuts in the rock.",
    "scorch marks" : "Blackened rock faces.",
    "marks" : "There are claw marks and scorch marks.",
  ]) );
  set_exits( ([
    "south" : DRAG_ROOMS+"commonrocky3",
    "southwest" : DRAG_ROOMS+"commonrocky2",
    "west" : DRAG_ROOMS+"common9",
    "northwest" : DRAG_ROOMS+"common6",
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

