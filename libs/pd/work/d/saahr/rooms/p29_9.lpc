#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p29_8",
    "south" : VPROOMS "p29_10",
    "east" : VPROOMS "p30_9"
  ]));
}
