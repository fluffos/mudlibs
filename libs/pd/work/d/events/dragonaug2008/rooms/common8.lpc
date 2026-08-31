
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
    "Beneath the shade of the southern mountain peaks, this open area "
    "is perfect for large gatherings. Some scratch and burn marks mar "
    "the rocky walls and ground, but the area is otherwise clean."
  );
  set_items( ([
    "peaks" : "They rise up against the sky.",
    "marks" : "Claw shaped marks gouged deeply in the rock walls, "
      "and some black charred spots on the ground.",
    "walls" : "Tall rocky walls that provide shade and protection.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "north" : DRAG_ROOMS+"common5",
    "northeast" : DRAG_ROOMS+"common6",
    "east" : DRAG_ROOMS+"common9",
    "west" : DRAG_ROOMS+"common7",
  ]) );
}

void reset() {
  int i = random(5);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

