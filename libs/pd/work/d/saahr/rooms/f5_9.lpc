#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "p4_9",
    "east" : VPROOMS "f6_9"
  ]));
}
