
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
    "The cave expands out into a huge tunnel here. There are many "
    "torches all over the walls, brightening the area. The rocky walls "
    "have occaisonal stripes of color in them here. Every surface has "
    "been smoothed down. A few specks in the walls twinkle in the firelight."
  );
  set_items( ([
    ({ "cave", "tunnel" }) : "A large tunnel that leads through the mountain.",
    "torches" : "Mostly oil torches, placed into holes bored into the walls.",
    "walls" : "They have stripes of color that run the length of the tunnel, "
      "and sometimes small twinkling specks.",
    "specks" : "Just some tiny bits of quartz or some other crystal."
  ]) );
  set_exits( ([
    "east" : DRAG_ROOMS+"bluepath1",
    "west" : DRAG_ROOMS+"gathering",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }
}

