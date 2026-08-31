#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p1_7",
    "south" : VPROOMS "p1_9",
    "east" : VPROOMS "p2_8"
  ]));
}
