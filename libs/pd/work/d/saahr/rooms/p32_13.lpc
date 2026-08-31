#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p32_12",
    "south" : VPROOMS "p32_14",
    "west" : VPROOMS "p31_13",
    "east" : VPROOMS "p33_13"
  ]));
}
