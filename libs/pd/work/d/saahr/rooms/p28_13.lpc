#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p28_12",
    "west" : VPROOMS "p27_13",
    "east" : VPROOMS "p29_13"
  ]));
}
