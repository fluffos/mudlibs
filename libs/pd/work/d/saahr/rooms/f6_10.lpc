#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f6_9",
    "west" : VPROOMS "f5_10",
    "east" : VPROOMS "f7_10"
  ]));
}
