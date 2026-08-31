#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p19_0",
    "west" : VPROOMS "p18_1",
    "east" : VPROOMS "p20_1"
  ]));
}
