#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f6_8",
    "south" : VPROOMS "f6_10",
    "southwest" : VPROOMS "f5_10",
    "west" : VPROOMS "f5_9"
  ]));
}
