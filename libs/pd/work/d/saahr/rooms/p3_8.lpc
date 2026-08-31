#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p3_7",
    "south" : VPROOMS "p3_9",
    "west" : VPROOMS "p2_8",
    "east" : VPROOMS "p4_8"
  ]));
}
