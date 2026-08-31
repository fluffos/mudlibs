#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p25_13",
    "west" : VPROOMS "p24_12",
    "east" : VPROOMS "p26_12"
  ]));
}
