#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "f24_11",
    "west" : VPROOMS "f23_10",
    "east" : VPROOMS "f25_10"
  ]));
}
