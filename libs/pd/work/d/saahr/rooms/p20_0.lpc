#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p20_1",
    "west" : VPROOMS "p19_0",
    "east" : VPROOMS "p21_0"
  ]));
}
