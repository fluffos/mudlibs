#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "f9_5",
    "southwest" : VPROOMS "f8_5",
    "southeast" : VPROOMS "f10_5",
    "east" : VPROOMS "f10_4"
  ]));
}
