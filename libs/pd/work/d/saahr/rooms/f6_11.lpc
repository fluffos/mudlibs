#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "f6_12",
    "west" : VPROOMS "f5_11",
    "east" : VPROOMS "f7_11"
  ]));
}
