#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p20_15",
    "west" : VPROOMS "p19_14",
    "east" : VPROOMS "p21_14"
  ]));
}
