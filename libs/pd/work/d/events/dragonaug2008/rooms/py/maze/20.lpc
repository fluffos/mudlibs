#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "north" : DRAG_ROOMS"py/maze/19",
    "south" : DRAG_ROOMS"py/maze/21",
  ]) );

  add_fake_exits( ({ "east", "west", "up", "down", "northeast", "northwest", "southeast", "southwest" }) );
}
