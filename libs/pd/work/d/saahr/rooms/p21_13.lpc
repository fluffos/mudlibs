#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f21_12",
    "south" : VPROOMS "p21_14",
    "west" : VPROOMS "p20_13",
    "east" : VPROOMS "p22_13"
  ]));
}
