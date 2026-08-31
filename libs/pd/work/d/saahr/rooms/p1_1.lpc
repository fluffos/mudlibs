#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_day_long(load_object(VPSERVER)->query_random_long(0)+
    "\n%^RESET%^%^ORANGE%^"
    "A sandy trail leads westward to a small beach."
    "%^RESET%^"
  );

  set_night_long(load_object(VPSERVER)->query_random_long(1)+
    "\n%^RESET%^%^ORANGE%^"
    "A sandy trail leads westward to a small beach."
    "%^RESET%^"
  );

  set_exits(([
    "west" : VPROOMS "p0_1",
    "south" : VPROOMS "p1_2",
    "southeast" : VPROOMS "p2_2"
  ]));
}
