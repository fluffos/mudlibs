#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "southeast" : VPROOMS "f28_5",
    "west" : VPROOMS "f26_4",
    "east" : VPROOMS "f28_4"
  ]));
}
