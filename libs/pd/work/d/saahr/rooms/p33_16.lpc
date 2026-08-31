#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p33_15",
    "west" : VPROOMS "p32_16",
    "east" : VPROOMS "p34_16"
  ]));
}
