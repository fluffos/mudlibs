#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_9",
    "south" : VPROOMS "p31_11",
    "west" : VPROOMS "p30_10",
    "east" : VPROOMS "p32_10"
  ]));
}
