#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f15_4",
    "south" : VPROOMS "f15_6",
    "west" : VPROOMS "f14_5",
    "east" : VPROOMS "f16_5"
  ]));
}
