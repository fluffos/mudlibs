#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p19_13",
    "west" : VPROOMS "p18_14",
    "east" : VPROOMS "p20_14"
  ]));
}
