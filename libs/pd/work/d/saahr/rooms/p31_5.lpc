#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_4",
    "south" : VPROOMS "p31_6",
    "west" : VPROOMS "p30_5",
    "east" : VPROOMS "p32_5"
  ]));
}
