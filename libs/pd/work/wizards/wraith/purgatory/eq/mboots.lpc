#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^BLACK%^M%^RESET%^%^ORANGE%^uc%^BOLD%^%^BLACK%^ky %^RESET%^%^ORANGE%^Boo%^BOLD%^%^BLACK%^ts%^RESET%^");
    
    set_short("%^BOLD%^%^BLACK%^M%^RESET%^%^ORANGE%^uc%^BOLD%^%^BLACK%^ky %^RESET%^%^ORANGE%^Boo%^BOLD%^%^BLACK%^ts%^RESET%^");
    set_long("%^ORANGE%^Made from the muck of rotting sewage, these boots provide a comfortable"
             "%^ORANGE%^ wear with a HORRIBLE stench.");
    set_id(({"boots"}));
    set_ac(9);            
    set_mass(39);
    set_type("boots");
    set_curr_value("gold", 1);  
    set_wear("%^ORANGE%^You recoil from the stench of rotting sewage.") ;
    set_remove("%^BOLD%^%^BLACK%^YAY!!!! you can smell again!");
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
