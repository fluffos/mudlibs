#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p27_0",
    "south" : VPROOMS "p27_2",
    "west" : VPROOMS "p26_1"
  ]));
}
