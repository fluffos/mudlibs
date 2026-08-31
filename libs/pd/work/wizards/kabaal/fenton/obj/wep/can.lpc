#include <std.h>
#include <fenton.h>
inherit WEAPON;
void create() {
::create();
    set_name("spraycan");
    set_short("A can of spray-paint");
    set_long("This is the can that the little bastard uses to vandalize things within his reach. "
" It can be used to spraypaint other adventurers you dislike.");
    set_id(({"paint", "spray can", "can"}));
    set_mass(10);
    set_value(180);
    set_type("blunt");
    set_hands(1);
    set_wield("You feel like a true bastard when you wield this can.");
    set_unwield("As you unwield the spraycan, you decide to act your own age.");
    set_wc(4);  
    set_ac(0); 
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(102) > 85) {
       write("You point your spraycan at your enemy and turn them %^BOLD%^%^BLUE%^blue%^RESET%^.");
       say((string)this_player()->query_cap_name()+
	  "aims and fires, leaving a %^BOLD%^%^BLUE%^blue%^RESET%^ cloud behind. "
	  +this_player()->query_possessive()+".");
    }
}


