#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

void create() {
  ::create();

  set("id",({"bow"}));
  set_name("bow");
  set_short("Bow of %^BOLD%^%^WHITE%^Light%^RESET%^");
  set("long","The bow feels light, and is just the right weight.");
  set_weight(10);
    set_curr_value("gold", 80);
  set_ac(1);
  set_wc(11);
  set_type("projectile");
  set_decay_rate(1000);
}

int query_auto_load() {
  if (this_player()->query_level() > 30)
  return 1;
}
