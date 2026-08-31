#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "p12_14",
    "east" : VPROOMS "p14_14"
  ]));
}
