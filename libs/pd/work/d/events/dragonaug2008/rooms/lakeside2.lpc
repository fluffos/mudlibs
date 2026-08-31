
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1,
  ]) );
  set_short("beside a lake");
  set_long(
    "A smooth expanse of rock leads gently down into a lake here. "
    "The clear water stretches out to the north, and across it a high "
    "cliff wall can be seen. A pile of huge boulders sits next to "
    "the rock wall to the east."
  );
  set_items( ([
    "rock" : "The ground is smooth rock with a scattering of sand.",
    "lake" : "It extends out to the north. The water is clear and clean.",
    "cliff" : "The cliff is on the other side of the lake, "
      "and hard to make out very well from here.",
    "boulders" : "Huge boulders, many twenty feet tall, seem to have "
      "fallen from the eastern wall into a pile here.",
    "wall" : "The wall to the east is solid rock.",
  ]) );
  set_listen("default", "Waves lap gently at the edge of the lake.");
  set_exits( ([
    "north" : DRAG_ROOMS+"lake8",
    "west" : DRAG_ROOMS+"lakeside1",
  ]) );
}


