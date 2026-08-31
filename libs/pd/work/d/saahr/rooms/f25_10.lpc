#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "southeast" : VPROOMS "f26_11",
    "west" : VPROOMS "f24_10",
    "east" : VPROOMS "f26_10"
  ]));
}
