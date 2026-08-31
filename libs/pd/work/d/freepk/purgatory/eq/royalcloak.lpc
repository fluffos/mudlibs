#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^WHITE%^R%^RESET%^%^RED%^o%^BOLD%^%^RED%^y%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^l C%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^k%^RESET%^");
    
    set_short("%^BOLD%^%^WHITE%^R%^RESET%^%^RED%^o%^BOLD%^%^RED%^y%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^l C%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^k%^RESET%^");
    set_long("%^RED%^Made with the Kings insignia sewn into the back, this is a cloak fit for all seasons.%^RESET%^");
    set_id(({"cloak"}));
    set_ac(3);            
    set_mass(10);
    set_type("cloak");
    set_curr_value("gold", 300);  
    set_limbs(({ "torso", "right arm", "left arm" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 75) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 75) return 0;
   write("No, no, no.. you've got it all wrong. You may not wear the %^BOLD%^%^WHITE%^R%^RESET%^%^RED%^o%^BOLD%^%^RED%^y%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^l C%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^k%^RESET%^");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
