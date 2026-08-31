#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_1",
    "south" : VPROOMS "p30_3",
    "west" : VPROOMS "p29_2",
    "east" : VPROOMS "p31_2"
  ]));
}
