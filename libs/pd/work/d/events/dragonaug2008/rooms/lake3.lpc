
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
    "A sheer cliff rises to the north and east. The lake extends out "
    "to the southwest. The water laps gently against the rock walls "
    "which enclose it."
  );
  set_items( ([
    "cliff" : "The cliff to the north and east rises far above your head.",
    "lake" : "It is very clear, and nothing can be seen moving beneath "
      "the surface.",
    "walls" : "Vertical walls of rock enclose this lake.",
  ]) );
  set_exits( ([
    "south" : DRAG_ROOMS+"bluelake",
    "southeast" : DRAG_ROOMS+"lake5",
    "west" : DRAG_ROOMS+"lake2",
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

