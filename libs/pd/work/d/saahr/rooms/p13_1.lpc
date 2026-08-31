#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p13_0",
    "south" : VPROOMS "p13_2",
    "west" : VPROOMS "p12_1",
    "east" : VPROOMS "p14_1"
  ]));
}
