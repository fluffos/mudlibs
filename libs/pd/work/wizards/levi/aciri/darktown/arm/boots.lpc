# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("boots");
    
set_short("%^BOLD%^%^BLACK%^Boots%^RESET%^");
    set_long("A pair of shiny, black boots.");
    set_id(({"boots"}));
    set_ac(20);            
    set_mass(2);
    set_type("boots");   
set_limbs(({"left foot", "right foot"
}));
set_properties(([
        "no steal" : 1,
]));
}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }


