#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^A Fluffy plumed hat%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^A Fluffy plumed hat%^RESET%^");
    set_long("A large brimmed hat with a long feather stuch in the brim to the right side. ");
    set_id(({"hat"}));
    set_ac(2);            
    set_mass(15);
    set_type("helmet");
    set_curr_value("gold", 1);  
    set_wear("The hat starts tickling your nose.") ;
    set_remove("You sneeze and the hat goes flying.......");
    set_limbs(({ "head" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
