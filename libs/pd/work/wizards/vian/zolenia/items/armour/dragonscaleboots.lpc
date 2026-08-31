#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("boots");
   set_short("%^BOLD%^dr%^GREEN%^ago%^RESET%^%^GREEN%^nsca%^RESET%^%^BOLD%^le b%^GREEN%^oo%^RESET%^%^GREEN%^t%^RESET%^%^BOLD%^s%^RESET%^");
   set_long("These boots appear to be constructed from dragon scales.");
   set_id(({ "boots", "dragonscale boots"}));
   set_weight(30);
   set_limbs(({"right foot", "left foot"}));
   set_type("boots");
    set_curr_value("gold", 140);
   set_ac(5);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}

