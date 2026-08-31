#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p3_13",
    "south" : VPROOMS "p3_15",
    "west" : VPROOMS "p2_14"
  ]));
}
