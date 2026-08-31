#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p6_0",
    "west" : VPROOMS "p5_1",
    "east" : VPROOMS "p7_1"
  ]));
}
