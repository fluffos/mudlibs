#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p16_15",
    "west" : VPROOMS "p15_14",
    "east" : VPROOMS "p17_14"
  ]));
}
