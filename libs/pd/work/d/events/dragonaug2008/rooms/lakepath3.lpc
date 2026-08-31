
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
    "The canyon leads farther north here. The canyon's sides are bare, "
    "but widen outwards near the top. Unfortunately they are too "
    "steep to climb. "
    "The open sky above is framed by the rocky walls."
  );
  set_items( ([
    "canyon" : "A path between high rocky walls.",
    "walls" : "Steep, uneven rock.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"lakepath4",
    "south" : DRAG_ROOMS+"lakepath2",
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

