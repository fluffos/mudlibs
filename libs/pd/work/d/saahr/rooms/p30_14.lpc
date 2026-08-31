#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_13",
    "south" : VPROOMS "p30_15",
    "west" : VPROOMS "p29_14",
    "east" : VPROOMS "p31_14"
  ]));
}
