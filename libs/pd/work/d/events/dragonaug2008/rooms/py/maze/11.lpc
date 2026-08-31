#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "southwest" : DRAG_ROOMS"py/maze/12",
    "east" : DRAG_ROOMS"py/maze/10",
  ]) );

  add_fake_exits( ({ "down", "west", "southeast" }) );
}
