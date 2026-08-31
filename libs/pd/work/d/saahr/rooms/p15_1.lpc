#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p15_0",
    "south" : VPROOMS "p15_2",
    "east" : VPROOMS "p16_1"
  ]));
}
