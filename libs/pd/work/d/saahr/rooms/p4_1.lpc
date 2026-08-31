#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p4_0",
    "southeast" : VPROOMS "p5_2",
    "east" : VPROOMS "p5_1"
  ]));
}
