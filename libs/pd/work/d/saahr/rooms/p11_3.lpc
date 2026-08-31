#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p11_2",
    "west" : VPROOMS "p10_3",
    "east" : VPROOMS "p12_3"
  ]));
}
