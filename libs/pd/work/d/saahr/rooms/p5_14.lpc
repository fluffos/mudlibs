#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p5_13",
    "west" : VPROOMS "p4_14",
    "east" : VPROOMS "p6_14"
  ]));
}
