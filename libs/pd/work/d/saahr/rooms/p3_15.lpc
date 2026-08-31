#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p3_14",
    "west" : VPROOMS "p2_15",
    "east" : VPROOMS "p4_15"
  ]));
}
