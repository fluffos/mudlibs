#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "p6_7",
    "west" : VPROOMS "f6_8",
    "east" : VPROOMS "f8_8"
  ]));
}
