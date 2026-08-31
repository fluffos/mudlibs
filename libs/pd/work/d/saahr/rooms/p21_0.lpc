#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "southwest" : VPROOMS "p20_1",
    "west" : VPROOMS "p20_0"
  ]));
}
