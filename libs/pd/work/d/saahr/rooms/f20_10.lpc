#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f21_9",
    "west" : VPROOMS "f19_10",
    "east" : VPROOMS "f21_10"
  ]));
}
