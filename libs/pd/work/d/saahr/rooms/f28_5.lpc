#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f28_4",
    "northwest" : VPROOMS "f27_4",
    "south" : VPROOMS "f28_6",
    "east" : VPROOMS "p29_5"
  ]));
}
