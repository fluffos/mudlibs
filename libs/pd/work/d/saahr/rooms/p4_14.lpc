#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p4_13",
    "south" : VPROOMS "p4_15",
    "east" : VPROOMS "p5_14"
  ]));
}
