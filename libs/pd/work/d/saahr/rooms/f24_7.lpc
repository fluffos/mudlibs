#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();
  set_properties( (load_object(VFSERVER)->query_properties() || ([])) +
    ([ "nymph_deed_room" : 1 ]));
  set_day_long(load_object(VFSERVER)->query_random_long(0)+
    "There is a small mound of dirt near one of the trees.");
  set_night_long(load_object(VFSERVER)->query_random_long(1)+
    "There is a small mound of dirt near one of the trees.");
  set_items( (query_items() || ([])) + 
    ([ ({"mound","dirt"}) : "Looks like something was digging." ]));
  set_exits(([
    "west" : VPROOMS "f23_7"
  ]));
}

void reset() {
  ::reset();
  if (!random(3)) set_property("nymph_deed_room",1);
}
