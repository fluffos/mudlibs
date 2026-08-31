
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
    "A sudden rise of rock to the east creates a small mesa. "
    "Atop it, several trees huddle together against the wind. The ground "
    "underfoot is quite even, and seems well-tread. Opposite the mesa, "
    "the ground suddenly falls straight down into a huge chasm. "
    "The walking space is very wide however, and connects a larger "
    "open area to the southeast with the open road to the northwest."
  );
  set_items( ([
    "mesa" : "The mesa is a raised area of rock about thirty feet high, with "
      "some trees clustered on top, taking up all the space.",
    "trees" : "Some spruce trees with grey-green needles. They grow very "
      "close together.",
    "ground" : "It is fairly smooth. Only a few pebbles and a light dust "
      "are sprinked around the flat rock.",
    "chasm" : "The chasm is very long and almost as wide. Only the faintest "
      "sight of the bottom can be seen, dizzyingly far below.",
  ]) );
  set_listen("default", "Winds blow through the chasm, making a deep sighing noise.");
  set_exits( ([
    "northwest" : DRAG_ROOMS+"dragnorth26",
    "southeast" : DRAG_ROOMS+"common1",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

