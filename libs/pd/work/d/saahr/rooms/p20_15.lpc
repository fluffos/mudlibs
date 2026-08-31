#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p20_14",
    "west" : VPROOMS "p19_15",
    "east" : VPROOMS "p21_15"
  ]));
}
