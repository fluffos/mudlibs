# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("platemail");
    
set_short("%^BOLD%^%^BLACK%^Bl%^RESET%^%^BOLD%^ack %^RESET%^Plat%^BOLD%^ema%^BLACK%^il%^RESET%^");
    set_long("The armour of darkness.");
    set_id(({"platemail", "plate"}));
    set_ac(26);            
    set_mass(150);
    set_type("body armour");   
set_limbs(({"head", "torso", "left arm", "right arm", "left leg", "right leg" }));
set_properties(([
        "no steal" : 1,
]));
}
int query_auto_load() { if (this_player()->query_level() >=100) return 1; }


