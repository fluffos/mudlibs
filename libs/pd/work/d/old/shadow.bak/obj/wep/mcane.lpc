#include <std.h>;
#include <shadow.h>;

inherit WEAPON;

void create() {
  ::create();

  set("id",({"staff","cane","mages cane","mage's cane"}));
  set_name("cane");
  set_short("Mage's Cane");
  set("long","This cane harnesses some unknown magical power.");
  set_weight(5);
    set_curr_value("gold", 140);
  set_ac(1);
  set_wc(9);
  set_type("blunt");
  set_decay_rate(1000);
}

int query_auto_load() {
  if (this_player()->query_level() > 27)
  return 1;
}
