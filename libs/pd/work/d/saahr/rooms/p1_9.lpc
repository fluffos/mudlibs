#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p1_8",
    "south" : VPROOMS "p1_10",
    "west" : VPROOMS "p0_9"
  ]));
}
