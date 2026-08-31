#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p15_15",
    "west" : VPROOMS "p14_14",
    "east" : VPROOMS "p16_14"
  ]));
}
