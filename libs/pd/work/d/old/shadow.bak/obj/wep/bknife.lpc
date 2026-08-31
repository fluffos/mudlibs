#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

void create() {
  ::create();

  set("id",({"butcherknife","knife","dagger"}));
  set_name("butcherknife");
  set("short","A Butcherknife");
  set("long","This knife is used for cutting meat.");
  set_weight(5);
    set_curr_value("gold", 40);
  set_wc(5);
  set_type("knife");
  set_decay_rate(100);
}

int query_auto_load() {
  if (this_player()->query_level() > 5)
  return 1;
}
