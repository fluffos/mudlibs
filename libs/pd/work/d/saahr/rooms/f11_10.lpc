#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "f11_11",
    "southeast" : VPROOMS "f12_11",
    "west" : VPROOMS "f10_10"
  ]));
}
