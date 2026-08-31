#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f9_4",
    "southeast" : VPROOMS "f9_6",
    "west" : VPROOMS "f7_5",
    "east" : VPROOMS "f9_5"
  ]));
}
