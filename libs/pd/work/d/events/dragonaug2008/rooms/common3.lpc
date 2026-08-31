
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
    "Beneath the shade of the mountain walls, this open gathering spot is "
    "quite inviting. There is enough room for many dragons to socialize. "
    "Some grooves have been worn in the rocky ground from long use. "
    "A few holes in the rocky wall are visible.",
  );
  set_items( ([
    "walls" : "Tall rocky walls that provide shade and protection "
      "from the wind.",
    "grooves" : "Long and about as wide as a dragon's rump.",
    "holes" : "They go in at a downward angle, probably for holding torches.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "southeast" : DRAG_ROOMS+"common6",
    "south" : DRAG_ROOMS+"common5",
    "west" : DRAG_ROOMS+"common2",
    "northwest" : DRAG_ROOMS+"whitecaveoutside",
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

