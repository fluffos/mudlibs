#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "p2_6",
    "east" : VPROOMS "p4_6"
  ]));
}
