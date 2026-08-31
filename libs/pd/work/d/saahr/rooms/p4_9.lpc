#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p4_8",
    "west" : VPROOMS "p3_9",
    "east" : VPROOMS "f5_9"
  ]));
}
