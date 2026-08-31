#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^RESET%^%^ORANGE%^Pl%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^ed %^BOLD%^%^BLACK%^Le%^RESET%^%^ORANGE%^ath%^BOLD%^%^BLACK%^er %^BOLD%^%^WHITE%^Armour%^RESET%^");
    
    set_short("%^ORANGE%^Pl%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^ed %^BOLD%^%^BLACK%^Le%^RESET%^%^ORANGE%^ath%^BOLD%^%^BLACK%^er %^BOLD%^%^WHITE%^Armour%^RESET%^");
    set_long("This armour is a hard leather with small iron plates sewn into it, it is very useful against fists and bludgeons.");
    set_id(({"armour"}));
    set_ac(9);            
    set_mass(189);
    set_type("body armor");
    set_curr_value("gold", 1);  
    set_limbs(({ "torso", "first arm", "second arm", "third arm", "fourth arm", "right foreleg", "left foreleg" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 54) return 1; }
