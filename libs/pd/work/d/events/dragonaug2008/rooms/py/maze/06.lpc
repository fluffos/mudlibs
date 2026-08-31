#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "southwest" : DRAG_ROOMS"py/maze/04",
    "south" : DRAG_ROOMS"py/maze/05",
    "east" : DRAG_ROOMS"py/maze/07",
  ]) );

  add_fake_exit("north");
  add_fake_exit("west");
}
