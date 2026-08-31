#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p29_12",
    "south" : VPROOMS "p29_14",
    "west" : VPROOMS "p28_13",
    "east" : VPROOMS "p30_13"
  ]));
}
