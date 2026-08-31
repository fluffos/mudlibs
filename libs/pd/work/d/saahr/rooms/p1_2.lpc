#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p1_1",
    "south" : VPROOMS "p1_3",
    "southeast" : VPROOMS "p2_3",
    "east" : VPROOMS "p2_2"
  ]));
}
