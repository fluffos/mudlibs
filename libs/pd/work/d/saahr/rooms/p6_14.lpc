#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p6_13",
    "south" : VPROOMS "p6_15",
    "west" : VPROOMS "p5_14",
    "east" : VPROOMS "p7_14"
  ]));
}
