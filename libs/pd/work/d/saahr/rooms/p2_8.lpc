#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p2_7",
    "south" : VPROOMS "p2_9",
    "west" : VPROOMS "p1_8",
    "east" : VPROOMS "p3_8"
  ]));
}
