#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p26_1",
    "west" : VPROOMS "p25_2",
    "east" : VPROOMS "p27_2"
  ]));
}
