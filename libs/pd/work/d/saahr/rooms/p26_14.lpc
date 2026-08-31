#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p26_13",
    "west" : VPROOMS "p25_14",
    "east" : VPROOMS "p27_14"
  ]));
}
