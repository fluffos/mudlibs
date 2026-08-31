#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p18_15",
    "west" : VPROOMS "p17_14",
    "east" : VPROOMS "p19_14"
  ]));
}
