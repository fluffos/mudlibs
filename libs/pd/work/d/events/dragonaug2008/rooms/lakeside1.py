
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
    "A rock wall rises straight up to the west, and the floor "
    "of the lake seems to drop off suddenly just a little ways out. "
    "The path leads southward back through the canyon."
  );
  set_items( ([
    "rock" : "The ground is all smooth rock with a light sand "
      "covering it.",
    "lake" : "A very clear lake. The water is still and unbroken.",
    "wall" : "The wall is sheer rock that encloses the lake.",
    "floor" : "It drops off suddenly into deep water about ten feet out.",
    ({ "path", "canyon" })  : "A wide expanse between vertical walls.",
  ]) );
  set_listen("default", "Waves lap gently at the edge of the lake.");
  set_exits( ([
    "north" : DRAG_ROOMS+"lake7",
    "northeast" : DRAG_ROOMS+"lake8",
    "east" : DRAG_ROOMS+"lakeside2",
    "southeast" : DRAG_ROOMS+"lakepath5",
    "northwest" : DRAG_ROOMS+"lake9",
  ]) );
}
