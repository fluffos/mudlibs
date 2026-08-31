#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_6",
    "south" : VPROOMS "p31_8",
    "west" : VPROOMS "p30_7",
    "east" : VPROOMS "p32_7"
  ]));
}
