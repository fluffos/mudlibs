#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^wh%^RESET%^%^WHITE%^it%^BOLD%^%^WHITE%^e l%^RESET%^%^WHITE%^eat%^BOLD%^%^WHITE%^her%^RESET%^%^WHITE%^ pa%^BOLD%^%^WHITE%^nt%^RESET%^%^WHITE%^s%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^wh%^RESET%^%^WHITE%^it%^BOLD%^%^WHITE%^e l%^RESET%^%^WHITE%^eat%^BOLD%^%^WHITE%^her%^RESET%^%^WHITE%^ pa%^BOLD%^%^WHITE%^nt%^RESET%^%^WHITE%^s%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^ Another peice of crude stichery, these pants look even worse then the shirt.%^RESET%^");
    set_id(({"pants", "pant"}));
    set_ac(6);            
    set_mass(28);
    set_type("pants");
    set_curr_value("gold", 49);  
    set_wear("%^BOLD%^%^WHITE%^You quiver as you slip on the pants.") ;
    set_remove("You let out a sigh of relief as the pants are removed.");
    set_limbs(({ "right leg", "left leg" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
