#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("robes");
   set_short("%^RED%^ruby %^RESET%^encrusted %^BLACK%^%^BOLD%^robes%^RESET%^");
   set_long("These robes are constructed from the finest black velvet in the land, encrusted all the way around with small rubies..");
   set_id(({ "dress", "ruby encrusted robes", "ruby robes"}));
   set_weight(5);
   set_limbs(({"right arm", "right leg", "left leg", "torso", "left arm"}));
   set_type("tunic");
    set_curr_value("gold", 600);
   set_ac(3);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
