#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p14_13",
    "south" : VPROOMS "p14_15",
    "west" : VPROOMS "p13_14",
    "east" : VPROOMS "p15_14"
  ]));
}
