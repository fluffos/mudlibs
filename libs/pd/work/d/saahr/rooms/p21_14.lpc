#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p21_13",
    "west" : VPROOMS "p20_14",
    "east" : VPROOMS "p22_14"
  ]));
}
