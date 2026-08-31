#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p28_3",
    "west" : VPROOMS "p27_2",
    "east" : VPROOMS "p29_2"
  ]));
}
