#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p31_10",
    "west" : VPROOMS "p30_9",
    "east" : VPROOMS "p32_9"
  ]));
}
