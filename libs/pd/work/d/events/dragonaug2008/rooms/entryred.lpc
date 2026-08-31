
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 1, "indoors" : 1, "mountain" : 1,
  ]) );
  set_short("a tunnel");
  set_long(
    "This large tunnel leads through the mountain. A few torches "
    "sit on the walls, lighting the area. Rocky walls are all "
    "around; some have streaks of rusty red running through them. "
    "The path forks to the north, and leads south into a larger cave."
  );
  set_items( ([
    "tunnel" : "A tunnel leading through the mountain.",
    "torches" : "Mostly oil torches, placed into holes bored into the walls.",
    "walls" : "Jagged stone with rusty red minerals streaked through.",
  ]) );
  set_exits( ([
    "northeast" : DRAG_ROOMS+"entrypath3",
    "south" : DRAG_ROOMS+"gathering",
    "northwest" : DRAG_ROOMS+"entrypath2",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("red dragon "+i))) {
    ob = new(DRAG_MOBS+"reddragon");
    ob->move(this_object());
  }
}

