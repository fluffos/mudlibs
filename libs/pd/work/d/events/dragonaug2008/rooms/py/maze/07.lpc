#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "west" : DRAG_ROOMS"py/maze/06",
    "south" : DRAG_ROOMS"py/maze/08",
    "northeast" : DRAG_ROOMS"py/maze/09",
  ]) );

  add_fake_exit("east");
}
