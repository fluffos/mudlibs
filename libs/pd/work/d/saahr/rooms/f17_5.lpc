#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "f16_5",
    "east" : VPROOMS "f18_5"
  ]));
}
