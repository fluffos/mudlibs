#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p15_1",
    "west" : VPROOMS "p14_0",
    "east" : VPROOMS "p16_0"
  ]));
}
