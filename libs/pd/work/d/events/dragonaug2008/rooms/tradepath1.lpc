
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
    "The Great Southern Ridge\n"
    "This is an open area set up against the side of the mountain. "
    "A large set of boulders has been set up together, and they are "
    "completely blackened from fire. Many dragons mill about, waiting "
    "in line or conversing. Paths lead in several directions."
  );
  set_items( ([
    "boulders" : "They are completely soot-black.",
    "paths" : "They lead north, east, and southward.",
  ]) );
  set_smell("default", "An intense charred smell fills the air.");
  set_exits( ([
    "north" : DRAG_ROOMS+"dragnorth44",
    "east" : DRAG_ROOMS+"tradepath2",
    "southeast" : DRAG_ROOMS+"entrypath1",
    "northwest" : DRAG_ROOMS+"dragnorth43",
  ]) );
}

void reset() {
  int i = 3+random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->set_swarm(1);
    if (random(2)) ob->set_moving(1);
    ob->set_speed(50);
    ob->move(this_object());
  }
  if (!present("dragon cook"))
    new(DRAG_MOBS+"dragoncook")->move(this_object());
}

