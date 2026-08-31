#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_day_long(load_object(VFSERVER)->query_random_long(0)+
    "\n%^RESET%^%^CYAN%^"
    "A small path leads down to a lake just northwest of here."
    "%^RESET%^"
  );

  set_night_long(load_object(VFSERVER)->query_random_long(1)+
    "\n%^RESET%^%^CYAN%^"
    "A small path leads down to a lake just northwest of here."
    "%^RESET%^"
  );

  set_items( (query_items() || ([])) + ([
    "lake" : "The water looks murky and full of trees from here.",
  ]) );

  set_exits(([
    "northwest" : VPROOMS "lake17h_8h",
    "south" : VPROOMS "f18_10",
    "east" : VPROOMS "f19_9"
  ]));
}
