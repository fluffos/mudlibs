#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p0_11",
    "south" : VPROOMS "p0_13",
    "east" : VPROOMS "p1_12"
  ]));
}
