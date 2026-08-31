#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f7_12",
    "south" : VPROOMS "p7_14",
    "west" : VPROOMS "p6_13",
    "east" : VPROOMS "p8_13"
  ]));
}
