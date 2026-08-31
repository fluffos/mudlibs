#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_9",
    "south" : VPROOMS "p30_11",
    "west" : VPROOMS "p29_10",
    "east" : VPROOMS "p31_10"
  ]));
}
