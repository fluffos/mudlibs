#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^A human skull%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^A human skull%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Morbid, nasty and still grinning, this skull can be used as a helmet at times.%^RESET%^ ");
    set_id(({"skull"}));
    set_ac(10);            
    set_mass(65);
    set_type("helmet");
    set_curr_value("gold", 1);  
    set_wear("%^BOLD%^%^WHITE%^AWWW NASTY!! There are still some brains left inside! You feel utterly dusgusted as the brains slither past your ear.") ;
    set_remove("You shake your head to rid yourself of the brains.");
    set_limbs(({ "head" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 55) return 1; }
