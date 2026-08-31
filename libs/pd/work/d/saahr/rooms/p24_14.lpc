#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p24_13",
    "west" : VPROOMS "p23_14",
    "east" : VPROOMS "p25_14"
  ]));
}
