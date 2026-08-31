#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p3_8",
    "west" : VPROOMS "p2_7",
    "east" : VPROOMS "p4_7"
  ]));
}
