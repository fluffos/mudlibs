#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p9_13",
    "west" : VPROOMS "p8_14",
    "east" : VPROOMS "p10_14"
  ]));
}
