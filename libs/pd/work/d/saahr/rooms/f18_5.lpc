#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f18_4",
    "south" : VPROOMS "f18_6",
    "west" : VPROOMS "f17_5",
    "east" : VPROOMS "f19_5"
  ]));
}
