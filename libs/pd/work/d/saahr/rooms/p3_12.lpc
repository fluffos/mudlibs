#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p3_11",
    "south" : VPROOMS "p3_13",
    "west" : VPROOMS "p2_12"
  ]));
}
