#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p3_12",
    "south" : VPROOMS "p3_14",
    "east" : VPROOMS "p4_13"
  ]));
}
