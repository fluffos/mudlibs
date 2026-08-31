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
    set_ac(20);            
    set_mass(235);
    set_type("body armor");
    set_curr_value("gold", 1); 
    set_wear( (: extra_worn :) );  
    set_remove("%^BOLD%^%^WHITE%^The slime dies as you rip it from your body.%^RESET%^");
    set_limbs(({ "head", "right hand", "left hand", "right arm", "left arm", "torso", "right leg", "left leg", "right foot", "left foot" 
}));
}
int extra_worn() {
    if((int)this_player()->query_level() < 89) {
        write("%^GREEN%^Awww gross, why would you want to wear that?%^RESET%^");
        say(this_player()->query_cap_name()+" gets grossed out and pukes all over the place as he tries to wear some nasty lookin slime.");
        notify_fail("%^GREEN%^Awww gross, why would you want to wear that?%^RESET%^");
        return 0;
    }
    write("%^BOLD%^%^GREEN%^The slime covers your entire body with a revolting crawling motion.%^RESET%^");
    say(this_player()->query_cap_name() + " makes you feel a little queasy as they lets some nasty looking slime cover their body>");
    return 1;

}
 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }
