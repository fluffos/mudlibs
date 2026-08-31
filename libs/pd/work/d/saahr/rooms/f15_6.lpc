#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f15_5",
    "northeast" : VPROOMS "f16_5",
    "southeast" : VPROOMS "f16_7",
    "west" : VPROOMS "f14_6"
  ]));
}
