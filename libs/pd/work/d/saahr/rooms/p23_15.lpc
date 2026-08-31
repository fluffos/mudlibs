#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p23_14",
    "west" : VPROOMS "p22_15",
    "east" : VPROOMS "p24_15"
  ]));
}
