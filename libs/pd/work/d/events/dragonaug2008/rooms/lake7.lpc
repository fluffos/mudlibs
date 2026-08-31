
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
    "The lake is very cold and very calm. It extends out to the north, and "
    "seems to be surrounded by rock walls. The shore is just south of here, "
    "and through the clear water the sudden drop into the deep lake is "
    "clearly visible."
  );
  set_items( ([
    "walls" : "They enclose the lake here in the mountains.",
    "shore" : "Solid ground that is only a little bit sandy.",
    "water" : "The water is extremely clear and calm.",
  ]) );
  set_exits( ([
    "east" : DRAG_ROOMS+"lake8",
    "south" : DRAG_ROOMS+"lakeside1",
    "west" : DRAG_ROOMS+"lake6",
    "northwest" : DRAG_ROOMS+"bluelake",
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

