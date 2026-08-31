#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p17_3",
    "west" : VPROOMS "p16_2",
    "east" : VPROOMS "p18_2"
  ]));
}
