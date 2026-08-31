#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f9_10",
    "southwest" : VPROOMS "f8_12",
    "west" : VPROOMS "f8_11"
  ]));
}
