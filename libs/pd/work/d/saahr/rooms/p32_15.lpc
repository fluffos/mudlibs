#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p32_14",
    "south" : VPROOMS "p32_16",
    "west" : VPROOMS "p31_15",
    "east" : VPROOMS "p33_15"
  ]));
}
