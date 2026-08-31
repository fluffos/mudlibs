#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p8_1",
    "south" : VPROOMS "p8_3",
    "east" : VPROOMS "p9_2"
  ]));
}
