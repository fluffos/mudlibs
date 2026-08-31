#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "f10_4",
    "northeast" : VPROOMS "f12_4",
    "south" : VPROOMS "f11_6",
    "west" : VPROOMS "f10_5"
  ]));
}
