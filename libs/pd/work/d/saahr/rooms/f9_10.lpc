#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f8_9",
    "south" : VPROOMS "f9_11",
    "east" : VPROOMS "f10_10"
  ]));
}
