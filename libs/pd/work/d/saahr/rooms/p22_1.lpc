#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "p23_0",
    "southwest" : VPROOMS "p21_2",
    "east" : VPROOMS "p23_1"
  ]));
}
