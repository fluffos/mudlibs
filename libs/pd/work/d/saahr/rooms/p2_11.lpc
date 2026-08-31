#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p2_10",
    "south" : VPROOMS "p2_12",
    "west" : VPROOMS "p1_11",
    "east" : VPROOMS "p3_11"
  ]));
}
