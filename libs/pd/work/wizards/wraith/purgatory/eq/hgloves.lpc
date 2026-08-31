#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^l%^RESET%^WHITE%^eat%^BOLD%^%^WHITE%^her%^RESET%^%^WHITE%^ gl%^BOLD%^%^WHITE%^ove%^RESET%^%^WHITE%^s%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^l%^RESET%^WHITE%^eat%^BOLD%^%^WHITE%^her%^RESET%^%^WHITE%^ gl%^BOLD%^%^WHITE%^ove%^RESET%^%^WHITE%^s%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^It looks like someone removed the skin from a corpses hand without tearing it!"
             "%^BOLD%^%^WHITE%^ These gloves are human hands! How morbid is that?");
    set_id(({"gloves"}));
    set_ac(5);            
    set_mass(25);
    set_type("gloves");
    set_curr_value("gold", 23);  
    set_wear("%^BOLD%^%^WHITE%^The gloves fit tightly on your hands, creaking with age.") ;
    set_remove("You remove the gloves with a sudden jerk of movement.");
    set_limbs(({ "right hand", "left hand" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
