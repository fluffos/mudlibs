#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f6_9",
    "south" : VPROOMS "f5_11",
    "east" : VPROOMS "f6_10"
  ]));
}
