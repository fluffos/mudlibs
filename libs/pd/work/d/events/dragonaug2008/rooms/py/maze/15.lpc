#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "west" : DRAG_ROOMS"py/maze/16",
    "north" : DRAG_ROOMS"py/maze/14",
  ]) );

  add_fake_exits( ({ "east", "south", "up", "down", "northeast", "northwest", "southeast", "southwest" }) );
}
