#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "southwest" : VPROOMS "f21_7",
    "southeast" : VPROOMS "f23_7",
    "east" : VPROOMS "f23_6"
  ]));
}
