#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/icebase";

void create() {
  ::create();
  set_exits( ([
    "west" : DRAG_ROOMS"py/maze/14",
    "north" : DRAG_ROOMS"py/maze/12",
  ]) );

  add_fake_exits( ({ "east", "northeast" }) );
}
