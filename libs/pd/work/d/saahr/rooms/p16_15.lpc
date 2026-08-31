#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p16_14",
    "west" : VPROOMS "p15_15",
    "east" : VPROOMS "p17_15"
  ]));
}
