#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p17_2",
    "west" : VPROOMS "p16_3",
    "east" : VPROOMS "p18_3"
  ]));
}
