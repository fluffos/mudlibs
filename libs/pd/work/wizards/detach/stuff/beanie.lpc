#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
  set_id(({"armour","beanie","hemjold's beanie"}));
  set_name("beanie");

set_short("%^RED%^He%^BOLD%^%^RED%^m%^YELLOW%^j%^RED%^o%^RESET%^%^RED%^ld's%^RESET%^ "
"%^RED%^pro%^BOLD%^%^RED%^p%^YELLOW%^e%^RED%^ll%^RESET%^%^RED%^or "
"%^RED%^be%^BOLD%^%^RED%^a%^YELLOW%^n%^RESET%^%^RED%^ie%^RESET%^");
  set_long("This is Hemjold's beanie.  A little propellor spins on top.");
  set_ac(0);
  set_limbs("head");
  set_type("beanie");
  set_weight(10);
  set_value(0);
  set_limbs(({"head"}));
}

void init() {
  ::init();
  add_action("spin","spin");
}

int spin(string str) {
  if (!str || str != "propellor") return 0;
  write("%^BOLD%^%^BLUE%^You spin your propellor on your beanie and hover briefly.");
  say(""+this_player()->query_cap_name()+" spins "+this_player()->query_possessive()+" propellor on "+this_player()->query_possessive()+" beanie and hovers briefly.");
  return 1;
}
int query_auto_load()
{                                   
if (this_player()->query_level() > 10) return 1;
}

