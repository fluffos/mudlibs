#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p4_6",
    "west" : VPROOMS "p3_7",
    "east" : VPROOMS "p5_7"
  ]));
}
