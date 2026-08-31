#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_10",
    "south" : VPROOMS "p30_12",
    "west" : VPROOMS "p29_11"
  ]));
}
