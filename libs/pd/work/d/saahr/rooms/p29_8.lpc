#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p29_9",
    "west" : VPROOMS "f28_8",
    "east" : VPROOMS "p30_8"
  ]));
}
