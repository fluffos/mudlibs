#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "south" : DRAG_ROOMS"py/maze/01",
    "east" : DRAG_ROOMS"py/maze/03",
  ]) );

  add_fake_exit("north");
}
