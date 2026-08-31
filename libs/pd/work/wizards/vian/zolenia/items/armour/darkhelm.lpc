#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("helm");
   set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k h%^RESET%^e%^BLACK%^%^BOLD%^lm%^RESET%^");
   set_long("This helm appears to be constructed from pure darkness.  It sucks the light from its immediate surroundings.");
   set_id(({ "helm", "dark helm"}));
   set_weight(30);
   set_limbs(({"head"}));
   set_type("helmet");
    set_curr_value("gold", 120);
   set_ac(7);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
