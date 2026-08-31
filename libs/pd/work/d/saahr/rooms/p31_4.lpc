#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_3",
    "south" : VPROOMS "p31_5",
    "west" : VPROOMS "p30_4",
    "east" : VPROOMS "p32_4"
  ]));
}
