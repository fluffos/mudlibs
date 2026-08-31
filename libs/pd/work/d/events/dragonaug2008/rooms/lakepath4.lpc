
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
    "The canyon leads farther north here. A few rocks lie around, "
    "but nothing very large. On one wall a ragged bird's nest is visible. "
    "The open sky above is framed by the rocky walls."
  );
  set_items( ([
    "canyon" : "A space between high rocky walls.",
    "rocks" : "Brown and grey rocks.",
    "wall" : "The wall is unremarkable rock.",
    "nest" : "Some twigs placed together. It is far up the wall, "
      "but seems empty.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"lakepath5",
    "south" : DRAG_ROOMS+"lakepath3",
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

