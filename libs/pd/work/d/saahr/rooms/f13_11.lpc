#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f13_10",
    "south" : VPROOMS "f13_12",
    "southwest" : VPROOMS "f12_12"
  ]));
}
