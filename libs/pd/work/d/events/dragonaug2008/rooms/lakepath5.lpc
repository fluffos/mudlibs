
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
    "The canyon begins to open up wider here. Several rocks are scattered "
    "around near the canyon walls, but the main path is clear. The open "
    "sky above is framed by the rocky walls."
  );
  set_items( ([
    "canyon" : "A path between high rocky walls.",
    "rocks" : "Brown and grey rocks.",
    "walls" : "They are very high and look pretty treacherous.",
  ]) );
  set_listen("default", "A small pebble clatters off the wall as it "
    "falls from above.");
  set_exits( ([
    "south" : DRAG_ROOMS+"lakepath4",
    "northwest" : DRAG_ROOMS+"lakeside1",
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

