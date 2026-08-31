
#include <std.h>

inherit PERIODIC_ROOM;

void create() { periodic_room::create(); }
void init() { periodic_room::init(); }

int periodic() {
  object *livs;

  livs = filter(all_inventory(this_object()), (: $1->is_living() :) );

  if (sizeof(livs)) {
    livs->add_hp(-(30+random(30)));
    return 1;
  }

  return 0;
}


