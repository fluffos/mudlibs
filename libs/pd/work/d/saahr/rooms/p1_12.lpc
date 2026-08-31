#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p1_13",
    "west" : VPROOMS "p0_12",
    "east" : VPROOMS "p2_12"
  ]));
}
