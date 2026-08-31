#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p29_15",
    "west" : VPROOMS "p28_16",
    "east" : VPROOMS "p30_16"
  ]));
}
