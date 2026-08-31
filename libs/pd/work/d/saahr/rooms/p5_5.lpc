#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_day_long(load_object(VPSERVER)->query_random_long(0)+
    "\n%^RESET%^%^ORANGE%^"
    "A rickety rope bridge spans the river to the east."
    "%^RESET%^"
  );
  set_night_long(load_object(VPSERVER)->query_random_long(1)+
    "\n%^RESET%^%^ORANGE%^"
    "A rickety rope bridge spans the river to the east."
    "%^RESET%^"
  );
  set_items( (query_items() || ([])) + ([
    "bridge" : "A rickety wooden bridge over the river."
  ]) );
  set_exits(([
    "southeast" : VPROOMS "p6_6",
    "west" : VPROOMS "p4_5",
    "east" : VPROOMS "bridge6_5"
  ]));
}
