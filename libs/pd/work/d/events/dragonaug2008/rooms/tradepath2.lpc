
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1,
  ]) );
  set_short("a mountain road");
  set_long(
    "The Great Southern Ridge\n"
    "This flat road is often filled with dragons, bartering their "
    "services or special kills. An open area spreads to the south, "
    "while a rock outcropping leads north over a chasm. Tall mountain "
    "peaks can be seen in the distance in all directions."
  );
  set_items( ([
    "road" : "As much a road as a mountain path can be.",
    "outcropping" : "An area of rock that sticks out into the chasm.",
    "chasm" : "A sudden drop off to the north.",
    ({ "mountain", "peaks" }) : "The mountain peaks rise against the sky, "
      "many topped with snow.",
  ]) );
  set_listen("default", "Some dragons talk amongst themselves.");
  set_exits( ([
    "north" : DRAG_ROOMS+"overlook",
    "east" : DRAG_ROOMS+"tradepath3",
    "southeast" : DRAG_ROOMS+"entrypath2",
    "south" : DRAG_ROOMS+"entrypath1",
    "west" : DRAG_ROOMS+"tradepath1",
    "northwest" : DRAG_ROOMS+"dragnorth44",
  ]) );
}

void reset() {
  int i = 3+random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

