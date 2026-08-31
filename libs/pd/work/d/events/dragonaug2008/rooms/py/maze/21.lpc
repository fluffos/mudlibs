#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "north" : DRAG_ROOMS"py/maze/20",
    "east" : DRAG_ROOMS"py/maze/22",
  ]) );

  add_fake_exits( ({ "south", "west", "up", "down", "northeast", "northwest", "southeast", "southwest" }) );
}
