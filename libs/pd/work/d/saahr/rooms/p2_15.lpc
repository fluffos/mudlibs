#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p2_14",
    "west" : VPROOMS "p1_15",
    "east" : VPROOMS "p3_15"
  ]));
}
