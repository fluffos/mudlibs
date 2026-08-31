#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p24_0",
    "south" : VPROOMS "p24_2",
    "west" : VPROOMS "p23_1",
    "east" : VPROOMS "p25_1"
  ]));
}
