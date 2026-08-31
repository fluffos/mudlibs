#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l S%^RESET%^%^ORANGE%^h%^BOLD%^%^ORANGE%^ie%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^d%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l S%^RESET%^%^ORANGE%^h%^BOLD%^%^ORANGE%^ie%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^d%^RESET%^");
    set_long("%^ORANGE%^Crafted by a master smith, this shield is guilded within an inch of its life and look to provide good armour.");
    set_id(({"shield"}));
    set_ac(5);            
    set_mass(28);
    set_type("shield");
    set_curr_value("gold", 45);  
    set_wear("%^ORANGE%^You stagger and dance around trying to get used to the shield.") ;
    set_remove("%^BOLD%^%^ORANGE%^You feel light as a feather as the shield drops off your arm.");
    set_limbs(({ "left hand", "left arm", "torso" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 100) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 75) return 0;
   write("No, no, no.. you've got it all wrong. You may not wear the %^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l S%^RESET%^%^ORANGE%^h%^BOLD%^%^ORANGE%^ie%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^d%^RESET%^");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
