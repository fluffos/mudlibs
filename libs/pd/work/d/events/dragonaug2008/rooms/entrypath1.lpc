
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
    "The mountain walls rise to the west. Large open areas can be clearly "
    "seen northwards, including a busy road nearby. This path is quite "
    "well traveled and has been completely cleared of obstructions. "
    "Dragons often seem to spend time here."
  );
  set_items( ([
    "mountain" : "The mountain walls create a protected area for trade.",
    "road" : "The road has several dragons on it.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "north" : DRAG_ROOMS+"tradepath2",
    "east" : DRAG_ROOMS+"entrypath2",
    "southeast" : DRAG_ROOMS+"entryblack",
    "northwest" : DRAG_ROOMS+"tradepath1",
  ]) );
}

void reset() {
  int i = 1+random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

