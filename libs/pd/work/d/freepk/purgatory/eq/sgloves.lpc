#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^GREEN%^Sl%^RESET%^%^GREEN%^im%^BOLD%^%^GREEN%^y G%^RESET%^%^GREEN%^lo%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^es%^RESET%^");
    
    set_short("%^BOLD%^%^GREEN%^Sl%^RESET%^%^GREEN%^im%^BOLD%^%^GREEN%^y G%^RESET%^%^GREEN%^lo%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^es%^RESET%^");
    set_long("%^GREEN%^These gloves look OHH so nast and revolting, as if someone"
             "%^GREEN%^ had dipped them in rotting meat and left them to decompose for a while.");
    set_id(({"gloves"}));
    set_ac(3);            
    set_mass(18);
    set_type("gloves");
    set_curr_value("gold", 2);  
    set_wear("%^BOLD%^%^GREEN%^Your stomach does flip-flops as it rejects the feeling of the slime on your hands.%^RESET%^") ;
    set_remove("%^GREEN%^Ahhhh that feels better.......");
    set_limbs(({ "right hand", "left hand" 
}));
}
 int query_auto_load() { if (this_player()->query_level() > 55) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 55) return 0;
   write("D'oh! Not being able to wear these must make you mad.....");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
