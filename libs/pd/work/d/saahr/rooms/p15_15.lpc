#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p15_14",
    "south" : VPROOMS "p15_16",
    "east" : VPROOMS "p16_15"
  ]));
}
