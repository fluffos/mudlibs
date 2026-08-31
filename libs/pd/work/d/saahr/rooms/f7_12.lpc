#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p7_13",
    "west" : VPROOMS "f6_12",
    "east" : VPROOMS "f8_12"
  ]));
}
