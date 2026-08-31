#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p27_14",
    "west" : VPROOMS "p26_13",
    "east" : VPROOMS "p28_13"
  ]));
}
