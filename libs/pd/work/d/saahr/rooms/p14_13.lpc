#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p14_14",
    "west" : VPROOMS "p13_13",
    "east" : VPROOMS "p15_13"
  ]));
}
