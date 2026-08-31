#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p12_13",
    "west" : VPROOMS "p11_14",
    "east" : VPROOMS "p13_14"
  ]));
}
