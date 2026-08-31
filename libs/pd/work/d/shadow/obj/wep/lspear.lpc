#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

void create() {
  ::create();

  set("id",({"spear","light spear","spear of light"}));
  set_name("spear");
  set_short("Spear of %^BOLD%^%^WHITE%^Light%^RESET%^");
  set("long","The end of the spear comes to a razor sharp edge.");
  set_weight(5);
    set_curr_value("gold", 85);
  set_wc(10);
  set_type("projectile");
  set_decay_rate(1000);
}

int query_auto_load() {
  if (this_player()->query_level() > 30)
  return 1;
}
