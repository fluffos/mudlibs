#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "p1_2",
    "south" : VPROOMS "p2_4",
    "southeast" : VPROOMS "p3_4",
    "east" : VPROOMS "p3_3"
  ]));
}
