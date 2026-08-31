#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "west" : DRAG_ROOMS"py/maze/02",
    "north" : DRAG_ROOMS"py/maze/04",
  ]) );

  add_fake_exit("east");
}
