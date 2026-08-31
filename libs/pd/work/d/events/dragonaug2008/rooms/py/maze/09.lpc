#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "southwest" : DRAG_ROOMS"py/maze/07",
    "northwest" : DRAG_ROOMS"py/maze/10",
  ]) );

  add_fake_exits( ({ "west", "east", "north", "south", "northeast", "southeast", "up", "down" }) );
}
