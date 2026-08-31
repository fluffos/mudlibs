#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "p2_2",
    "south" : VPROOMS "p3_4",
    "southeast" : VPROOMS "p4_4",
    "west" : VPROOMS "p2_3"
  ]));
}
