#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p24_12",
    "south" : VPROOMS "p24_14",
    "west" : VPROOMS "p23_13",
    "east" : VPROOMS "p25_13"
  ]));
}
