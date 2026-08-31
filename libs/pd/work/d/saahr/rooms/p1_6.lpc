#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p1_5",
    "south" : VPROOMS "p1_7",
    "west" : VPROOMS "p0_6"
  ]));
}
