#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f22_6",
    "southwest" : VPROOMS "f22_8",
    "east" : VPROOMS "f24_7"
  ]));
}
