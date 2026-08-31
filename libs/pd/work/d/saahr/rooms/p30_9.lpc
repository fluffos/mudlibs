#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p30_10",
    "west" : VPROOMS "p29_9",
    "east" : VPROOMS "p31_9"
  ]));
}
