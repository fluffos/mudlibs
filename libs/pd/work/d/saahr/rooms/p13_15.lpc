#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p13_16",
    "west" : VPROOMS "p12_15",
    "east" : VPROOMS "p14_15"
  ]));
}
