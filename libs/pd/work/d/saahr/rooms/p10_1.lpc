#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p10_2",
    "west" : VPROOMS "p9_1",
    "east" : VPROOMS "p11_1"
  ]));
}
