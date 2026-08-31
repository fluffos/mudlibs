#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p10_14",
    "west" : VPROOMS "p9_15",
    "east" : VPROOMS "p11_15"
  ]));
}
