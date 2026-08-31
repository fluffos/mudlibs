#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "f18_12",
    "west" : VPROOMS "f17_11",
    "east" : VPROOMS "f19_11"
  ]));
}
