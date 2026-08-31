#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f9_4",
    "south" : VPROOMS "f9_6",
    "west" : VPROOMS "f8_5"
  ]));
}
