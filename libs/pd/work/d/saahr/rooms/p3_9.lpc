#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p3_8",
    "west" : VPROOMS "p2_9",
    "east" : VPROOMS "p4_9"
  ]));
}
