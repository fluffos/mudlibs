#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l P%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^s%^RESET%^");
    
    set_short("%^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l P%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^s%^RESET%^");
    set_long("%^MAGENTA%^Just another regular pair of pants that have had the rear of a ruler in them.");
    set_id(({"pants"}));
    set_ac(2);            
    set_mass(25);
    set_type("leggings");
    set_curr_value("gold", 300);  
    set_limbs(({ "right leg", "left leg" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 75) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 75) return 0;
   write("No, no, no.. you've got it all wrong. You may not wear the %^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l P%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^s%^RESET%^");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
