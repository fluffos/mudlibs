#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p17_16",
    "west" : VPROOMS "p16_15",
    "east" : VPROOMS "p18_15"
  ]));
}
