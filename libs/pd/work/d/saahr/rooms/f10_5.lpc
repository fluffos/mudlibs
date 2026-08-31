#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f9_4",
    "southwest" : VPROOMS "f9_6",
    "east" : VPROOMS "f11_5"
  ]));
}
