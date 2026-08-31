#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f16_11",
    "northwest" : VPROOMS "f15_11",
    "east" : VPROOMS "f17_12"
  ]));
}
