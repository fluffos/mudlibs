#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p28_1",
    "west" : VPROOMS "p27_0",
    "east" : VPROOMS "p29_0"
  ]));
}
