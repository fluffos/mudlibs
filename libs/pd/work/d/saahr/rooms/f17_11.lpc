#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "southeast" : VPROOMS "f18_12",
    "west" : VPROOMS "f16_11",
    "east" : VPROOMS "f18_11"
  ]));
}
