#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f9_5",
    "northwest" : VPROOMS "f8_5",
    "northeast" : VPROOMS "f10_5",
    "southwest" : VPROOMS "f8_7"
  ]));
}
