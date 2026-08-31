#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p23_1",
    "west" : VPROOMS "p22_2",
    "east" : VPROOMS "p24_2"
  ]));
}
