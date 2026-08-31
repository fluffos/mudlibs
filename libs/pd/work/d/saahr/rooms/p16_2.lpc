#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p16_1",
    "south" : VPROOMS "p16_3",
    "east" : VPROOMS "p17_2"
  ]));
}
