#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ring");
   set_short("%^BOLD%^dr%^GREEN%^ago%^RESET%^%^GREEN%^nsca%^RESET%^%^BOLD%^le r%^GREEN%^i%^RESET%^%^GREEN%^n%^RESET%^%^BOLD%^g%^RESET%^");
   set_long("This ring appears to be constructed from dragon scales.");
   set_id(({ "ring", "dragonscale ring"}));
   set_weight(1);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
    set_curr_value("gold", 200);
   set_ac(2);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 29);
}

