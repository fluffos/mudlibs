# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("plate gloves");
    
set_short("%^BOLD%^%^BLACK%^Bla%^RESET%^%^BOLD%^ck %^RESET%^Plate %^BOLD%^Glov%^BLACK%^es%^RESET%^");
    set_long("Brilliantly crafted, tarnished silver plate gloves.");
    set_id(({"plate gloves", "gloves"}));
    set_ac(15);            
    set_mass(5);
    set_type("gloves");   
set_limbs(({"right hand", "left hand"}));
    set_properties(([
        "no steal" : 1,
]));
}
int query_auto_load() { if (this_player()->query_level() >=100) return 1; }

