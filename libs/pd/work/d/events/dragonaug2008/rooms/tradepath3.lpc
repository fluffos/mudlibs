
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
    "This flat road is often filled with dragons, bartering their "
    "services or special kills. A wide chasm spreads out to the north, "
    "and a much smaller one to the south, but the road is large enough "
    "for four dragons to walk abreast. Mountain peaks can be seen in "
    "the distance in all directions."
  );
  set_items( ([
    "road" : "As much a road as a path through a mountain can be.",
    "chasm" : "The chasm to the north is very wide and hard to "
      "see across from here. The one to the south is narrow, but "
      "just as deep.",
    "peaks" : "They rise up against the sky.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "east" : DRAG_ROOMS+"tradepath4",
    "west" : DRAG_ROOMS+"tradepath2",
  ]) );
}

void reset() {
  int i = 2+random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

