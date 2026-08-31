#include <std.h>

inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^BLACK%^A skullcap%^RESET%^");
    
    set_short("%^BOLD%^%^BLACK%^A skullcap%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^It looks to be part of a skull chopped to fit a human head.%^RESET%^");
    set_id(({"cap", "skullcap"}));
    set_ac(2);            
    set_mass(15);
    set_type("cap");
    set_curr_value("gold", 15);  
    set_wear("You place the cap on top of your head.") ;
    set_remove("You remove the cap in disgust.");
    set_limbs(({ "head" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
