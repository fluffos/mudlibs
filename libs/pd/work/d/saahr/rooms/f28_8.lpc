#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f28_7",
    "south" : VPROOMS "f28_9",
    "east" : VPROOMS "p29_8"
  ]));
}
