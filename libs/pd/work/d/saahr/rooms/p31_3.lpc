#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "south" : VPROOMS "p31_4",
    "west" : VPROOMS "p30_3",
    "east" : VPROOMS "p32_3"
  ]));
}
