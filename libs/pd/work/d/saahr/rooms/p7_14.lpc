#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p7_13",
    "south" : VPROOMS "p7_15",
    "west" : VPROOMS "p6_14",
    "east" : VPROOMS "p8_14"
  ]));
}
