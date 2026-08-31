
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
    "The mountain rises up to the south of here, with some bright tunnels "
    "leading through it. Across a gap to the west, another path "
    "can be seen. Several rocks have been set up to form paths leading "
    "from the tunnels to the trading area farther north."
  );
  set_items( ([
    "mountain" : "The mountain is a huge mass of rock, pushed upwards "
      "over the centuries.",
    "tunnels" : "Two tunnels lead southwards through the mountain.",
    "gap" : "A sudden deep drop off.",
    "rocks" : "They have been arranged in sweeping lines to create "
      "clean pathways to follow."
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "north" : DRAG_ROOMS+"tradepath5",
    "east" : DRAG_ROOMS+"entrypath4",
    "south" : DRAG_ROOMS+"entrywhite",
    "southwest" : DRAG_ROOMS+"entryred",
    "northwest" : DRAG_ROOMS+"tradepath4",
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

