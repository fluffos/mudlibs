#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ring");
   set_short("%^RED%^ruby %^RESET%^encrusted %^BLACK%^%^BOLD%^ring%^RESET%^");
   set_long("This ring is constructed from the finest onyx in the land, encrusted all the way around with small rubies..");
   set_id(({ "ring", "ruby encrusted ring", "ruby ring"}));
   set_weight(5);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
    set_curr_value("gold", 500);
   set_ac(3);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
