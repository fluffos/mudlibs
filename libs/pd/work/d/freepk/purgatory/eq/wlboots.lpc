#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^to%^RESET%^%^WHITE%^rn l%^BOLD%^%^WHITE%^eat%^RESET%^%^WHITE%^her%^BOLD%^%^WHITE%^ bo%^RESET%^%^WHITE%^ots%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^to%^RESET%^%^WHITE%^rn l%^BOLD%^%^WHITE%^eat%^RESET%^%^WHITE%^her%^BOLD%^%^WHITE%^ bo%^RESET%^%^WHITE%^ots%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Faded and ripped with use, these boots have holes where your heel and big toe should be....%^RESET%^");
    set_id(({"boots"}));
    set_ac(5);            
    set_mass(27);
    set_type("boots");
    set_curr_value("gold", 76);  
    set_wear("You wiggle your toes in the holes.") ;
    set_remove("The boots flop off your feet");
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
