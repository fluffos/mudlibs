#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p29_1",
    "south" : VPROOMS "p29_3",
    "west" : VPROOMS "p28_2",
    "east" : VPROOMS "p30_2"
  ]));
}
