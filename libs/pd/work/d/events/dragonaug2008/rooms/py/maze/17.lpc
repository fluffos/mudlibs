#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "south" : DRAG_ROOMS"py/maze/14",
    "west" : DRAG_ROOMS"py/maze/18",
  ]) );

  add_fake_exits( ({ "east", "north", "up", "down", "northeast", "northwest", "southeast", "southwest" }) );
}
