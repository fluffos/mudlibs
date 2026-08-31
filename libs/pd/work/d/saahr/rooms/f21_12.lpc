#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f20_11",
    "northeast" : VPROOMS "f22_11",
    "south" : VPROOMS "p21_13"
  ]));
}
