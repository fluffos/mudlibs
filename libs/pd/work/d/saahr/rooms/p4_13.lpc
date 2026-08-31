#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p4_14",
    "west" : VPROOMS "p3_13",
    "east" : VPROOMS "p5_13"
  ]));
}
