#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p29_16",
    "west" : VPROOMS "p28_15",
    "east" : VPROOMS "p30_15"
  ]));
}
