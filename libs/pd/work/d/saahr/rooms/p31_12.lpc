#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_11",
    "south" : VPROOMS "p31_13",
    "west" : VPROOMS "p30_12",
    "east" : VPROOMS "p32_12"
  ]));
}
