#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p6_1",
    "west" : VPROOMS "p5_0",
    "east" : VPROOMS "p7_0"
  ]));
}
