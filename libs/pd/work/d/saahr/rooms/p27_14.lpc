#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p27_13",
    "south" : VPROOMS "p27_15",
    "west" : VPROOMS "p26_14",
    "east" : VPROOMS "p28_14"
  ]));
}
