#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p20_0",
    "northeast" : VPROOMS "p21_0",
    "southwest" : VPROOMS "p19_2",
    "west" : VPROOMS "p19_1"
  ]));
}
