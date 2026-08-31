#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p27_14",
    "south" : VPROOMS "p27_16",
    "west" : VPROOMS "p26_15",
    "east" : VPROOMS "p28_15"
  ]));
}
