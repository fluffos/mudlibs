#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p30_6",
    "south" : VPROOMS "p30_8",
    "west" : VPROOMS "p29_7",
    "east" : VPROOMS "p31_7"
  ]));
}
