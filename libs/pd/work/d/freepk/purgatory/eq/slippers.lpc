#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("slippers");
    
    set_short("slippers");
    set_long("A comfy pair of slippers fitted to match the Queens foot.");
    set_id(({"slippers"}));
    set_ac(1);            
    set_mass(20);
    set_type("boots");
    set_curr_value("gold", 10);  
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
