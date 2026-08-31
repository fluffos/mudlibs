#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("boots");
   set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k b%^RESET%^o%^BLACK%^%^BOLD%^ots%^RESET%^");
   set_long("These boots appear to be constructed from pure darkness.  They suck the light from its immediate surroundings.");
   set_id(({ "boots", "dark boots"}));
   set_weight(30);
   set_limbs(({"right foot", "left foot"}));
   set_type("boots");
    set_curr_value("gold", 140);
   set_ac(4);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
