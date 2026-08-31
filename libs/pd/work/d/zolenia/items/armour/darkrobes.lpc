#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("robes");
   set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k r%^RESET%^o%^BLACK%^%^BOLD%^bes%^RESET%^");
   set_long("These robes appears to be constructed from pure darkness.");
   set_id(({ "dress", "dark robes"}));
   set_weight(5);
   set_limbs(({"right arm", "right leg", "left leg", "torso", "left arm"}));
   set_type("tunic");
    set_curr_value("gold", 200);
   set_ac(2);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}

