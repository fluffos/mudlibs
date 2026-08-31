#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_4",
    "south" : VPROOMS "p30_6",
    "west" : VPROOMS "p29_5",
    "east" : VPROOMS "p31_5"
  ]));
}
