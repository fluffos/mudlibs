#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p32_13",
    "south" : VPROOMS "p32_15",
    "west" : VPROOMS "p31_14"
  ]));
}
