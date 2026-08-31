#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("robes");
  set("id", ({ "robe", "robes" }) );
  set("short", "Mages Robes of %^BOLD%^%^WHITE%^Light%^RESET%^");
  set("long", "The %^BOLD%^%^WHITE%^white robes%^RESET%^ help to shed light in the %^BOLD%^%^BLACK%^dark city%^RESET%^ of their origin.");
  set_type("robes");
  set_ac(2);
  set_limbs( ({"left arm", "right arm", "torso"}) );
  set_weight(10);
    set_curr_value("gold", 75);
}

int query_auto_load() {
  if (this_player()->query_level() > 32)
  return 1;
}
