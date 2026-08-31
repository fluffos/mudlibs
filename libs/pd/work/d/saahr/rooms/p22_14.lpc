#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p22_15",
    "west" : VPROOMS "p21_14",
    "east" : VPROOMS "p23_14"
  ]));
}
