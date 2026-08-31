#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "northwest" : VPROOMS "p3_3",
    "south" : VPROOMS "p4_5",
    "west" : VPROOMS "p3_4"
  ]));
}
