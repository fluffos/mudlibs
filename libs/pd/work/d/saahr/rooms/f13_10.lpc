#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "f13_11",
    "southwest" : VPROOMS "f12_11",
    "southeast" : VPROOMS "f14_11"
  ]));
}
