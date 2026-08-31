#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f25_6",
    "south" : VPROOMS "f25_8",
    "east" : VPROOMS "f26_7"
  ]));
}
