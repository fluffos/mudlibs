#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_day_long(load_object(VPSERVER)->query_random_long(0)+
    "\n%^RESET%^%^ORANGE%^"
    "A long, sturdy bridge spans the river to the west."
    "%^RESET%^"
  );

  set_night_long(load_object(VPSERVER)->query_random_long(1)+
    "\n%^RESET%^%^ORANGE%^"
    "A long, sturdy bridge spans the river to the west."
    "%^RESET%^"
  );

  set_items( (query_items() || ([])) + ([
    "bridge" : "The bridge is wide and solid-looking.",
  ]) );

  set_exits(([
    "northwest" : VPROOMS "p4_1",
    "southeast" : VPROOMS "p6_3",
    "west" : VPROOMS "bridge4_2",
    "east" : VPROOMS "p6_2"
  ]));
}
