#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p10_15",
    "west" : VPROOMS "p9_14",
    "east" : VPROOMS "p11_14"
  ]));
}
