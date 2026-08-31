#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

void create() {
  ::create();

  set("id",({"sword","light sword","sword of light"}));
  set_name("sword");
  set_short("Sword of %^BOLD%^%^WHITE%^Light%^RESET%^");
  set("long","The blade seems to glow of it's own accord.");
  set_weight(10);
    set_curr_value("gold", 110);
  set_wc(9);
  set_type("blade");
  set_decay_rate(1000);
}

int query_auto_load() {
  if (this_player()->query_level() > 35)
  return 1;
}
