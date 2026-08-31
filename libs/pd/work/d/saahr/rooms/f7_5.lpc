#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_day_long(load_object(VFSERVER)->query_random_long(0)+
    "\n%^RESET%^%^ORANGE%^"
    "A rickety rope bridge spans the river to the west."
    "%^RESET%^"
  );
  set_night_long(load_object(VFSERVER)->query_random_long(1)+
    "\n%^RESET%^%^ORANGE%^"
    "A rickety rope bridge spans the river to the west."
    "%^RESET%^"
  );
  set_items( (query_items() || ([])) + ([
    "bridge" : "A rickety wooden bridge over the river."
  ]) );
  set_exits(([
    "northwest" : VPROOMS "f6_4",
    "south" : VPROOMS "f7_6",
    "west" : VPROOMS "bridge6_5",
    "east" : VPROOMS "f8_5"
  ]));
}
