#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p2_8",
    "south" : VPROOMS "p2_10",
    "east" : VPROOMS "p3_9"
  ]));
}
