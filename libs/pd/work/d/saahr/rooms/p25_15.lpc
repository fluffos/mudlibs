#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p25_14",
    "west" : VPROOMS "p24_15",
    "east" : VPROOMS "p26_15"
  ]));
}
