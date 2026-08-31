#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f23_10",
    "southwest" : VPROOMS "f21_12",
    "east" : VPROOMS "f23_11"
  ]));
}
