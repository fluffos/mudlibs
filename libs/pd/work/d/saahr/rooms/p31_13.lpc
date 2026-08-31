#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_12",
    "west" : VPROOMS "p30_13",
    "east" : VPROOMS "p32_13"
  ]));
}
