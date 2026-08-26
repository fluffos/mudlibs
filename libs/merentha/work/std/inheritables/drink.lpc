// Petrarch
// Merentha Lib 1.0
// drink.c

#include <std.h>
#include "drink.h"

inherit OBJECT;

int strength;

void set_strength(int i) { strength=i; }

void init() {
::init();
  add_action("cmd_drink", "drink");
}

int cmd_drink(string str) {
  if(!str || !id(str)) return notify_fail("Drink what?\n");
  this_player()->heal((strength?strength:10));
  message("action","You drink "+query_short()+".", this_player());
  message("action",this_player()->query_cap_name()+" drinks "+query_short()+".", environment(this_player()), this_player());
  remove();
  return 1;
}

int is_drink() { return 1; }

