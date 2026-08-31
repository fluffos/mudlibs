#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f22_6",
    "southwest" : VPROOMS "f20_8",
    "southeast" : VPROOMS "f22_8",
    "east" : VPROOMS "campsite"
  ]));
}
