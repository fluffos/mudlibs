
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 1, "night light" : 0, "indoors" : 1, "mountain" : 1,
  ]) );
  set_short("a tunnel");
  set_long(
    "This is a dark tunnel leading through the mountain. Several "
    "veins of coal can be seen in the walls and floor. Soft rocks "
    "and coal chunks break easily underfoot. Light can be seen "
    "dimly in every direction."
  );
  set_items( ([
    "tunnel" : "A tunnel leading through the mountain.",
    "coal" : "The coal is a soft black mineral that runs through "
      "the regular stone walls and floor.",
    "light" : "Firelight comes from every direction.",
  ]) );
  set_smell("default", "The smell of coal dust fills the air.");
  set_exits( ([
    "north" : DRAG_ROOMS+"entrypath2",
    "southeast" : DRAG_ROOMS+"gathering",
    "northwest" : DRAG_ROOMS+"entrypath1",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("black dragon "+i))) {
    ob = new(DRAG_MOBS+"blackdragon");
    ob->move(this_object());
  }
}

