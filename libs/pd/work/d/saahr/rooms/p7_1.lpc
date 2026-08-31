#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p7_2",
    "west" : VPROOMS "p6_1",
    "east" : VPROOMS "p8_1"
  ]));
}
