#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("gloves");
   set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k g%^RESET%^l%^BLACK%^%^BOLD%^oves%^RESET%^");
   set_long("These gloves appear to be constructed from pure darkness.  They suck the light from its immediate surroundings.");
   set_id(({ "gloves", "dark gloves"}));
   set_weight(10);
   set_limbs(({"right hand", "left hand"}));
   set_type("gloves");
    set_curr_value("gold", 90);
   set_ac(3);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
