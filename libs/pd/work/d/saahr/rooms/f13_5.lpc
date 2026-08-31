#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f13_4",
    "northeast" : VPROOMS "f14_4",
    "southeast" : VPROOMS "f14_6"
  ]));
}
