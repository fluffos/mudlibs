#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "p5_5",
    "south" : VPROOMS "p6_7"
  ]));
}
