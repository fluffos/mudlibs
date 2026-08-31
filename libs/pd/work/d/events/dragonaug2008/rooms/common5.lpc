
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
    "Lightly shaded by mountain walls and peaks, this open gathering spot "
    "is quite inviting. A deep chasm opens to the west, but there is enough "
    "room here for many dragons to socialize. Some grooves have been worn "
    "in the rocky ground from long use. A lizard scurries down into the "
    "darkness of the chasm."
  );
  set_items( ([
    "walls" : "Tall rocky walls that provide shade and protection.",
    "peaks" : "They rise up against the sky.",
    "chasm" : "It is narrow, but very deep.",
    "grooves" : "Long and about as wide as a dragon's rump.",
    "lizard" : "It's long gone.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "north" : DRAG_ROOMS+"common3",
    "east" : DRAG_ROOMS+"common6",
    "southeast" : DRAG_ROOMS+"common9",
    "south" : DRAG_ROOMS+"common8",
    "southwest" : DRAG_ROOMS+"common7",
    "northwest" : DRAG_ROOMS+"common2",
  ]) );
}

void reset() {
  int i = random(4);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

