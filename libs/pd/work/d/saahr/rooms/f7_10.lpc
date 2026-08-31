#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f8_9",
    "south" : VPROOMS "f7_11",
    "west" : VPROOMS "f6_10"
  ]));
}
