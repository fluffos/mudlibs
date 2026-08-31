#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "west" : VPROOMS "f28_5",
    "east" : VPROOMS "p30_5"
  ]));
}
