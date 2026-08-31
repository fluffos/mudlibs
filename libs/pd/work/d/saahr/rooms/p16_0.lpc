#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p16_1",
    "west" : VPROOMS "p15_0",
    "east" : VPROOMS "p17_0"
  ]));
}
