#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("armour");
   set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k a%^RESET%^r%^BLACK%^%^BOLD%^mour%^RESET%^");
   set_long("This armour appears to be constructed from pure darkness.  It sucks the light from its immediate surroundings.");
   set_id(({ "armour", "dark armour"}));
   set_weight(70);
   set_limbs(({"torso", "right arm", "left arm"}));
   set_type("armour");
    set_curr_value("gold", 260);
   set_ac(10);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
