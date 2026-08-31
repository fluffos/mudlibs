#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p2_5",
    "south" : VPROOMS "p2_7",
    "east" : VPROOMS "p3_6"
  ]));
}
