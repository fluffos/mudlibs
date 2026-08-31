#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p23_14",
    "west" : VPROOMS "p22_13",
    "east" : VPROOMS "p24_13"
  ]));
}
