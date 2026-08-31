
#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^RESET%^%^ORANGE%^Pl%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^ed %^BOLD%^%^BLACK%^Le%^RESET%^%^ORANGE%^ath%^BOLD%^%^BLACK%^er%^BOLD%^%^WHITE%^ Leggings%^RESET%^");
    
    set_short("%^RESET%^%^ORANGE%^Pl%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^ed %^BOLD%^%^BLACK%^Le%^RESET%^%^ORANGE%^ath%^BOLD%^%^BLACK%^er %^BOLD%^%^WHITE%^Leggings%^RESET%^");
    set_long("This armour is a hard leather with small iron plates sewn into it, it is very useful against fists and bludgeons.");
    set_id(({"leggings", "armour"}));
    set_ac(4);            
    set_mass(36);
    set_type("leggings");
    set_curr_value("gold", 300);  
    set_limbs(({ "right foreleg", "left foreleg", "left rear leg", "right rear leg"  
}));
}
 int query_auto_load() { if (this_player()->query_level() > 54) return 1; }
