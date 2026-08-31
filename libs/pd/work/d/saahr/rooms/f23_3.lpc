#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "southwest" : VPROOMS "f22_4",
    "southeast" : VPROOMS "f24_4",
    "west" : VPROOMS "f22_3",
    "east" : VPROOMS "f24_3"
  ]));
}
