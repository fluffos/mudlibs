
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
    "This corner of the lake is very calm. A small branch floats slowly "
    "towards a very small break in the northern cliff, where several larger "
    "bits of debris have gathered over time. The bulk of the lake lies to the "
    "southeast, and a sheer wall rises to the west."
  );
  set_items( ([
    "lake" : "A large body of water in which you are swimming.",
    "branch" : "It has a few grey needles still attached.",
    "break" : "The break in the cliff is less than a foot wide. "
      "A small trickle of water runs through it.",
    "cliff" : "The cliff to the north rises far above your head.",
    "debris" : "Branches, leaves, and a few feathers.",
    "wall" : "Another vertical wall of rock which encloses the lake.",
  ]) );
  set_exits( ([
    "east" : DRAG_ROOMS+"lake2",
    "southeast" : DRAG_ROOMS+"lake4",
  ]) );
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }
}

