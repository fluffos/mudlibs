#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p18_1",
    "west" : VPROOMS "p17_2",
    "east" : VPROOMS "p19_2"
  ]));
}
