#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "p32_4",
    "south" : VPROOMS "p32_6",
    "west" : VPROOMS "p31_5"
  ]));
}
