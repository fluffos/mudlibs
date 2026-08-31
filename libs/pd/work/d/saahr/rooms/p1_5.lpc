#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p1_4",
    "south" : VPROOMS "p1_6",
    "east" : VPROOMS "p2_5"
  ]));
}
