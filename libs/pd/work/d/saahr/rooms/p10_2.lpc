#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p10_1",
    "south" : VPROOMS "p10_3",
    "west" : VPROOMS "p9_2"
  ]));
}
