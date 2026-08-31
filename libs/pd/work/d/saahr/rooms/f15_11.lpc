#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f16_10",
    "southeast" : VPROOMS "f16_12",
    "west" : VPROOMS "f14_11"
  ]));
}
