#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("%^BOLD%^%^BLUE%^R%^GREEN%^o%^BLUE%^y%^GREEN%^a%^BLUE%^l %^GREEN%^C%^BLUE%^a%^GREEN%^p%^BLUE%^e%^RESET%^");
  set("id", ({ "cape", "royal cape" }) );
  set("short", "A %^BOLD%^%^BLUE%^R%^GREEN%^o%^BLUE%^y%^GREEN%^a%^BLUE%^l %^GREEN%^C%^BLUE%^a%^GREEN%^p%^BLUE%^e%^RESET%^");
  set("long", "The colors swirl in brilliant %^BOLD%^%^BLUE%^blues%^RESET%^ and %^BOLD%^%^GREEN%^greens%^RESET%^.");
  set_type("cloak");
  set_ac(2);
  set_limbs( ({ "torso", "left arm", "right arm" }) );
  set_weight(10);
    set_curr_value("gold", 60);
}

int query_auto_load() {
  if (this_player()->query_level() > 21)
  return 1;
}
