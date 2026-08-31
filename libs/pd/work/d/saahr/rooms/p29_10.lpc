#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p29_9",
    "south" : VPROOMS "p29_11",
    "west" : VPROOMS "f28_10",
    "east" : VPROOMS "p30_10"
  ]));
}
