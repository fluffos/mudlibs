#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_11",
    "south" : VPROOMS "p30_13",
    "west" : VPROOMS "p29_12",
    "east" : VPROOMS "p31_12"
  ]));
}
