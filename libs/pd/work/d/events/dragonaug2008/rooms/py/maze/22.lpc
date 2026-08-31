#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "west" : DRAG_ROOMS"py/maze/21",
    "south" : DRAG_ROOMS"py/maze/23",
  ]) );

  add_fake_exits( ({ "east", "north", "up", "down", "northeast", "northwest", "southeast", "southwest" }) );
}
