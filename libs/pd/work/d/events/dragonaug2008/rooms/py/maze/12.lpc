#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "south" : DRAG_ROOMS"py/maze/13",
    "northeast" : DRAG_ROOMS"py/maze/11",
  ]) );

  add_fake_exits( ({ "up", "down", "northwest", "east" }) );
}
