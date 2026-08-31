#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p29_2",
    "west" : VPROOMS "p28_3",
    "east" : VPROOMS "p30_3"
  ]));
}
