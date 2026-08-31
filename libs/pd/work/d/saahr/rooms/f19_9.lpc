#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f20_8",
    "south" : VPROOMS "f19_10",
    "west" : VPROOMS "f18_9",
    "east" : VPROOMS "f20_9"
  ]));
}
