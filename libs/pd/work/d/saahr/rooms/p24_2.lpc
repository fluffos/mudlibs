#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p24_1",
    "west" : VPROOMS "p23_2",
    "east" : VPROOMS "p25_2"
  ]));
}
