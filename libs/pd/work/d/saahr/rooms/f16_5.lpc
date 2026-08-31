#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_exits(([
    "northeast" : VPROOMS "f17_4",
    "southwest" : VPROOMS "f15_6",
    "southeast" : VPROOMS "f17_6",
    "west" : VPROOMS "f15_5",
    "east" : VPROOMS "f17_5"
  ]));
}
