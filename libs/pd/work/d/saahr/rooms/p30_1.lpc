#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p30_2",
    "west" : VPROOMS "p29_1",
    "east" : VPROOMS "p31_1"
  ]));
}
