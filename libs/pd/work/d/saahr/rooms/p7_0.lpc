#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "p6_0",
    "east" : VPROOMS "p8_0"
  ]));
}
