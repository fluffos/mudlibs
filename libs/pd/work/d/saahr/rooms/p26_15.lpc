#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p26_16",
    "west" : VPROOMS "p25_15",
    "east" : VPROOMS "p27_15"
  ]));
}
