#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p9_3",
    "west" : VPROOMS "p8_2",
    "east" : VPROOMS "p10_2"
  ]));
}
