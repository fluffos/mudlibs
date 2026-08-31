#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p16_0",
    "south" : VPROOMS "p16_2",
    "west" : VPROOMS "p15_1",
    "east" : VPROOMS "p17_1"
  ]));
}
