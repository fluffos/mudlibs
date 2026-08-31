#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f26_6",
    "northeast" : VPROOMS "f27_6",
    "south" : VPROOMS "f26_8",
    "southeast" : VPROOMS "f27_8",
    "west" : VPROOMS "f25_7",
    "east" : VPROOMS "f27_7"
  ]));
}
