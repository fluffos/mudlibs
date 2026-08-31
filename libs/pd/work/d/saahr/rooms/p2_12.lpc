#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p2_11",
    "south" : VPROOMS "p2_13",
    "west" : VPROOMS "p1_12",
    "east" : VPROOMS "p3_12"
  ]));
}
