#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p19_1",
    "west" : VPROOMS "p18_0",
    "east" : VPROOMS "p20_0"
  ]));
}
