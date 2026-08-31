#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_long(
    "A small footbridge crosses to the northwest, over the river. "
    "Lemon and apple trees grow wild along the sides of this "
    "small clearing."
  );

  set_exits(([
    "northwest" : VPROOMS "town13_9",
    "east" : VPROOMS "f15_10"
  ]));
}
