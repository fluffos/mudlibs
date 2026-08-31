#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "south" : DRAG_ROOMS"py/maze/03",
    "northeast" : DRAG_ROOMS"py/maze/06",
    "east" : DRAG_ROOMS"py/maze/05",
  ]) );

  add_fake_exit("west");
}
