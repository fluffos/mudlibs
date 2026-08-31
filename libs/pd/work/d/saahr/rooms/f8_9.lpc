#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f8_8",
    "southwest" : VPROOMS "f7_10",
    "southeast" : VPROOMS "f9_10"
  ]));
}
