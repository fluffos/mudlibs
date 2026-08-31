# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("vest");
    
set_short("%^RED%^A Corduroy Vest%^RESET%^");
    set_long("%^RED%^A plain corduroy vest.  It is extremely resistant to all types of force.  %^YELLOW%^The insignia of Carnage is stitched into the left breast with gold thread.%^RESET%^");
    set_id(({"vest", "corduroy vest"}));
    set_ac(20);            
    set_mass(5);
    set_type("vest");   
set_limbs(({"torso", "head"
}));
set_properties(([
        "no steal" : 1,
]));
}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }


