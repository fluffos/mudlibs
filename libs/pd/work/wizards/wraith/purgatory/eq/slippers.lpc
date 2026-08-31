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
    set_mass(2);
    set_type("boot");
    set_curr_value("gold", 1);  
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
