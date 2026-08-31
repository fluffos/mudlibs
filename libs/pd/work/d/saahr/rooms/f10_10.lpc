#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "f10_11",
    "west" : VPROOMS "f9_10",
    "east" : VPROOMS "f11_10"
  ]));
}
