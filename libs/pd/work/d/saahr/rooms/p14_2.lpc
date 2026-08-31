#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p14_1",
    "south" : VPROOMS "p14_3",
    "west" : VPROOMS "p13_2",
    "east" : VPROOMS "p15_2"
  ]));
}
