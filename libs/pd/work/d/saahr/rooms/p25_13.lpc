#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p25_12",
    "west" : VPROOMS "p24_13",
    "east" : VPROOMS "p26_13"
  ]));
}
