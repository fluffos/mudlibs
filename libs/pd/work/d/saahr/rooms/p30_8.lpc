#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_7",
    "west" : VPROOMS "p29_8",
    "east" : VPROOMS "p31_8"
  ]));
}
