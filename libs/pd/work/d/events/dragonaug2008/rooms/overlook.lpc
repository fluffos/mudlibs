
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
    "Just off the trading area, this scenic overlook offers a view "
    "of the surrounding area. A large chasm surrounds the rocky outcrop "
    "on three sides. Across the chasm, the side of a plateau of baked "
    "red earth can be seen. It is the tallest point around. A large "
    "valley sits just north of an open gathering spot to the northwest. "
    "Some dragons can be seen flying in the distance, and the mountain "
    "rises to take up the view to the south."
  );
  set_items( ([
    "chasm" : "A deep gash in the earth that drops down into nothing.",
    "outcrop" : "The area you are standing on.",
    "plateau" : "It is the tallest point visible, so it's impossible "
      "to see anything on top of it from here.",
    "valley" : "It looks very dark and sinister.",
    "mountain" : "The peaks of the mountain are snowy, and dark spots "
      "can be seen down at the base.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "south" : DRAG_ROOMS+"tradepath2",
  ]) );
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

