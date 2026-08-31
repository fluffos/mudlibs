#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p18_0",
    "south" : VPROOMS "p18_2",
    "west" : VPROOMS "p17_1",
    "east" : VPROOMS "p19_1"
  ]));
}
