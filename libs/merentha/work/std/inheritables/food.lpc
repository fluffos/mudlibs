// Petrarch
// Merentha Lib 1.0
// food.c

#include <std.h>
#include "food.h"

inherit OBJECT;

int strength;

void set_strength(int i) { strength=i; }

void init() {
::init();
  add_action("cmd_eat", "eat");
}

int cmd_eat(string str) {
  if(!str || !id(str)) return notify_fail("Eat what?\n");
  this_player()->heal((strength?strength:10));
  message("action","You eat "+query_short()+".", this_player());
  message("action",this_player()->query_cap_name()+" eats "+query_short()+".", environment(this_player()), this_player());
  remove();
  return 1;
}

int is_food() { return 1; }

