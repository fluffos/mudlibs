#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f28_9",
    "southwest" : VPROOMS "f27_11",
    "west" : VPROOMS "f27_10",
    "east" : VPROOMS "p29_10"
  ]));
}
