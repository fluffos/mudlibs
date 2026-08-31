#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l B%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^s%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l B%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^s%^RESET%^");
    set_long("%^orange%^Made by a dead cooper, these boots are extremely uncomfortable.%^RESET%^");
    set_id(({"boots"}));
    set_ac(7);            
    set_mass(35);
    set_type("boots");
    set_curr_value("gold", 1);  
    set_wear("%^ORANGE%^You wiggle your toes with self-importance.%^RESET%^") ;
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 100) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 75) return 0;
   write("No, no, no.. you've got it all wrong. You may not wear the %^BOLD%^%^WHITE%^R%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^y%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^l B%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^s%^RESET%^.");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
