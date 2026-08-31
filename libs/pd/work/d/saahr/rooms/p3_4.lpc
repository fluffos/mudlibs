#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p3_3",
    "northwest" : VPROOMS "p2_3",
    "southeast" : VPROOMS "p4_5",
    "east" : VPROOMS "p4_4"
  ]));
}
