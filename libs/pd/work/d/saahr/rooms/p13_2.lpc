#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p13_1",
    "west" : VPROOMS "p12_2",
    "east" : VPROOMS "p14_2"
  ]));
}
