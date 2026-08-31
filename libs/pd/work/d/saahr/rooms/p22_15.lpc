#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p22_14",
    "south" : VPROOMS "p22_16",
    "west" : VPROOMS "p21_15",
    "east" : VPROOMS "p23_15"
  ]));
}
