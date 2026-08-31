#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f9_11",
    "west" : VPROOMS "f7_12",
    "east" : VPROOMS "f9_12"
  ]));
}
