#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f19_9",
    "west" : VPROOMS "f18_10",
    "east" : VPROOMS "f20_10"
  ]));
}
