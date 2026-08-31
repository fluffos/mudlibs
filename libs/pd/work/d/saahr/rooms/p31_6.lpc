#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p31_5",
    "south" : VPROOMS "p31_7",
    "west" : VPROOMS "p30_6"
  ]));
}
