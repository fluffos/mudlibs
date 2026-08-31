#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p17_15",
    "west" : VPROOMS "p16_16",
    "east" : VPROOMS "p18_16"
  ]));
}
