# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("plate boots");
    
set_short("%^BOLD%^%^BLACK%^Bla%^RESET%^%^BOLD%^ck %^RESET%^Plate %^BOLD%^Boo%^BLACK%^ts%^RESET%^");
    set_long("Brilliantly crafted, tarnished silver plate boots.");
    set_id(({"plate boots", "boots"}));
    set_ac(15);            
    set_mass(5);
    set_type("boots");   
set_limbs(({"right foot", "left foot"}));
    set_properties(([
        "no steal" : 1,
]));
}
int query_auto_load() { if (this_player()->query_level() >=100) return 1; }

