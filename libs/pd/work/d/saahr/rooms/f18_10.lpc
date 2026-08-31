#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f18_9",
    "west" : VPROOMS "f17_10",
    "east" : VPROOMS "f19_10"
  ]));
}
