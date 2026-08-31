#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p11_15",
    "west" : VPROOMS "p10_14",
    "east" : VPROOMS "p12_14"
  ]));
}
