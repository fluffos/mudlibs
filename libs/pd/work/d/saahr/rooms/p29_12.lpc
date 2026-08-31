#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p29_13",
    "west" : VPROOMS "p28_12",
    "east" : VPROOMS "p30_12"
  ]));
}
