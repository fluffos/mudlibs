#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "southeast" : DRAG_ROOMS"py/maze/09",
    "west" : DRAG_ROOMS"py/maze/11",
  ]) );

  add_fake_exits( ({ "north", "south", "up", "southwest" }) );
}
