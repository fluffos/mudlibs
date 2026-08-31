#include <std.h>

inherit MONSTER;

int is_undead();

void create() {
  monster::create();
  this_object()->set_undead(1);
}

int is_undead() { return this_object()->query_undead(); }
