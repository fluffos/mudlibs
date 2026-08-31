#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f11_10",
    "northeast" : VPROOMS "f13_10",
    "west" : VPROOMS "f11_11"
  ]));
}
