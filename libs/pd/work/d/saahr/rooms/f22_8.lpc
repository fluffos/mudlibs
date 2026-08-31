#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f21_7",
    "northeast" : VPROOMS "f23_7",
    "east" : VPROOMS "f23_8"
  ]));
}
