#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f25_10",
    "west" : VPROOMS "f25_11",
    "east" : VPROOMS "f27_11"
  ]));
}
