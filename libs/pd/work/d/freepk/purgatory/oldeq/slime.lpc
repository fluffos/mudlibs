#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
int extra_worn();
void create() {
::create();
  
    set_name("%^GREEN%^Nas%^BOLD%^%^GREEN%^ty lo%^RESET%^%^GREEN%^okin%^BOLD%^%^GREEN%^g sl%^RESET%^%^GREEN%^im%^BOLD%^%^GREEN%^e%^RESET%^");
    
    set_short("%^GREEN%^Nas%^BOLD%^%^GREEN%^ty lo%^RESET%^%^GREEN%^okin%^BOLD%^%^GREEN%^g sl%^RESET%^%^GREEN%^im%^BOLD%^%^GREEN%^e%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^The residue of a thousand years of rot and disease.%^RESET%^");
    set_id(({"slime"}));
    set_ac(16);            
    set_mass(235);
    set_type("body armor");
    set_curr_value("gold", 1); 
    set_wear("%^GREEN%^Awwww now thats just not right.%^RESET%^" );  
    set_remove("%^BOLD%^%^WHITE%^The slime dies as you rip it from your body.%^RESET%^");
    set_limbs(({ "head", "right hand", "left hand", "right arm", "left arm", "torso", "right leg", "left leg", "right foot", "left foot" 
}));
}

 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "%^BOLD%^%^BLACK%^Purgatory %^BOLD%^%^WHITE%^Sk%^BOLD%^%^BLACK%^ele%^BOLD%^%^WHITE%^to%^BOLD%^%^BLACK%^n Guard%^RESET%^%^RED%^") return 0;
   write("Now, just why would you want to cover yourself in slime?");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

