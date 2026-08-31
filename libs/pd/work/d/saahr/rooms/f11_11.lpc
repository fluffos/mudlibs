#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f11_10",
    "south" : VPROOMS "f11_12",
    "west" : VPROOMS "f10_11",
    "east" : VPROOMS "f12_11"
  ]));
}
