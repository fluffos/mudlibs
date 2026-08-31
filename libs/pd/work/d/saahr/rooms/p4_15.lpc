#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p4_14",
    "west" : VPROOMS "p3_15",
    "east" : VPROOMS "p5_15"
  ]));
}
