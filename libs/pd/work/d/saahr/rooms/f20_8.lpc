#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f19_7",
    "northeast" : VPROOMS "f21_7",
    "southwest" : VPROOMS "f19_9",
    "southeast" : VPROOMS "f21_9"
  ]));
}
