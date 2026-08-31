#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p2_6",
    "south" : VPROOMS "p2_8",
    "east" : VPROOMS "p3_7"
  ]));
}
