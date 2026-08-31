
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
    "Beneath the shade of a mesa, this open gathering spot is quite inviting. "
    "A deep chasm opens to the south, but there is enough room here for many "
    "dragons to socialize. Some grooves have been worn in the rocky ground "
    "from long use."
  );
  set_items( ([
    "mesa" : "The mesa is a rise of flat rock with trees growing on top.",
    "trees" : "They huddle together atop the mesa, taking up all the space.",
    "chasm" : "The chasm is narrow but very deep.",
    "grooves" : "Long and about as wide as a dragon's rump.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "north" : DRAG_ROOMS+"whitecaveoutside",
    "east" : DRAG_ROOMS+"common3",
    "southeast" : DRAG_ROOMS+"common5",
    "west" : DRAG_ROOMS+"common1",
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

