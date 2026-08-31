#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_10",
    "south" : VPROOMS "p31_12",
    "east" : VPROOMS "p32_11"
  ]));
}
