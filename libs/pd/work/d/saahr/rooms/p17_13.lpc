#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_exits(([
    "north" : VPROOMS "f17_12",
    "south" : VPROOMS "p17_14",
    "west" : VPROOMS "p16_13"
  ]));
}
