#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_2",
    "south" : VPROOMS "p30_4",
    "west" : VPROOMS "p29_3",
    "east" : VPROOMS "p31_3"
  ]));
}
