#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^A human skull%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^A human skull%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Morbid, nasty and still grinning, this skull can be used as a helmet at times.%^RESET%^ ");
    set_id(({"skull"}));
    set_ac(3+random(4));            
    set_mass(25);
    set_type("helmet");
    set_curr_value("gold", 1);  
    set_wear("%^BOLD%^%^WHITE%^AWWW NASTY!! There are still some brains left inside! You feel utterly dusgusted as the brains slither past your ear.") ;
    set_remove("You shake your head to rid yourself of the brains.");
    set_limbs(({ "head" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 55) return 1; }
int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 55) return 0;
   write("Why, in the name of the gods, would you want to wear a skull?");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
