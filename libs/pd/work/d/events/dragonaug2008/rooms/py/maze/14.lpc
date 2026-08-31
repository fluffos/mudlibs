#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "south" : DRAG_ROOMS"py/maze/15",
    "north" : DRAG_ROOMS"py/maze/17",
    "east" : DRAG_ROOMS"py/maze/13",
  ]) );

  add_fake_exits( ({ "west", "southeast" }) );
}
