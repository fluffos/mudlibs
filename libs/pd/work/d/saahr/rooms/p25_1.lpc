#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p25_0",
    "west" : VPROOMS "p24_1",
    "east" : VPROOMS "p26_1"
  ]));
}
