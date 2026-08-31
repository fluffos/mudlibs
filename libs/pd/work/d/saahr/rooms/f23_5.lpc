#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "f22_5",
    "east" : VPROOMS "f24_5"
  ]));
}
