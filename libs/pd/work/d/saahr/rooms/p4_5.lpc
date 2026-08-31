#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p4_4",
    "northwest" : VPROOMS "p3_4",
    "east" : VPROOMS "p5_5"
  ]));
}
