#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p6_6",
    "southeast" : VPROOMS "f7_8",
    "west" : VPROOMS "p5_7"
  ]));
}
