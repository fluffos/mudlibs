#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "p20_1",
    "southwest" : VPROOMS "p18_3",
    "west" : VPROOMS "p18_2"
  ]));
}
