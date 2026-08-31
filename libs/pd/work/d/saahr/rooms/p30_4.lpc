#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_3",
    "south" : VPROOMS "p30_5",
    "east" : VPROOMS "p31_4"
  ]));
}
