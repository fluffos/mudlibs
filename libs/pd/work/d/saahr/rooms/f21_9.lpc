#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f20_8",
    "southwest" : VPROOMS "f20_10",
    "west" : VPROOMS "f20_9",
    "east" : VPROOMS "f22_9"
  ]));
}
