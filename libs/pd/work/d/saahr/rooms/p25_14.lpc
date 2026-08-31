#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p25_15",
    "west" : VPROOMS "p24_14",
    "east" : VPROOMS "p26_14"
  ]));
}
