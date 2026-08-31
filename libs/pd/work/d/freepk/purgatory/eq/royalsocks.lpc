#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l S%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^k%^BOLD%^%^MAGENTA%^s%^RESET%^");
    
    set_short("%^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l S%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^k%^BOLD%^%^MAGENTA%^s%^RESET%^");
    set_long("%^MAGENTA%^Its just a pair of socks pulled from a dead persons feet, what did you think they were gonna be?");
    set_id(({"socks"}));
    set_ac(1);            
    set_mass(15);
    set_type("socks");
    set_curr_value("gold", 50);  
    set_limbs(({ "right foot", "left foot" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 75) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 75) return 0;
   write("No, no, no.. you've got it all wrong. You may not wear the %^BOLD%^%^MAGENTA%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^l S%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^k%^BOLD%^%^MAGENTA%^s%^RESET%^");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

