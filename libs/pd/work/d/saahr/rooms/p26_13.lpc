#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p26_12",
    "south" : VPROOMS "p26_14",
    "west" : VPROOMS "p25_13",
    "east" : VPROOMS "p27_13"
  ]));
}
