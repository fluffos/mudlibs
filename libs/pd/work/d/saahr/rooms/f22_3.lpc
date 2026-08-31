#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "f21_3",
    "east" : VPROOMS "f23_3"
  ]));
}
