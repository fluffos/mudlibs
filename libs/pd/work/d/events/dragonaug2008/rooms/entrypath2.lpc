
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
    "The mountain rises up to the south of here, with some dark tunnels "
    "leading through it. Across a gap to the east, another path "
    "can be seen. The ground is bare and there doesn't seem to be "
    "anything of consequence here."
  );
  set_items( ([
    "mountain" : "The mountain is a huge mass of rock, pushed upwards "
      "over the centuries.",
    "tunnels" : "Two tunnels lead southwards through the mountain.",
    "gap" : "A sudden deep drop off.",
    "ground" : "Just rock.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "southeast" : DRAG_ROOMS+"entryred",
    "south" : DRAG_ROOMS+"entryblack",
    "west" : DRAG_ROOMS+"entrypath1",
    "northwest" : DRAG_ROOMS+"tradepath2",
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

