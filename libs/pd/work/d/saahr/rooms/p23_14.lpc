#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p23_13",
    "south" : VPROOMS "p23_15",
    "west" : VPROOMS "p22_14",
    "east" : VPROOMS "p24_14"
  ]));
}
