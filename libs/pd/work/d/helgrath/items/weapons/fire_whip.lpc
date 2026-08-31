#include <std.h>

inherit WEAPON;

void create()
{
    ::create();
    set_name("fire whip");
    set_id(({ "whip", "fire whip" }));
   set_short("%^BOLD%^%^RED%^Long whip%^RESET%^");
    set_long("A long red whip that emits small amounts of smoke.");
    set_weight(15 + random(10));
    set_curr_value("gold", 100 + random(75));
    set_wc(12);
    set_ac(1);
    set_type("flail"); // blade, blunt, axe, etc.
    set_decay_rate(3000);
    
    set_hit( (: this_object(), "weapon_hit" :) );
    
    set_wield("%^BOLD%^%^RED%^The whip sets itself on fire!"); // message to display when wielded
    set_unwield("The whip burns itself out.");
}

int weapon_hit() 
{
	int result;
	object atk;
	int num;
	int attack;
    atk = (object)this_player()->query_current_attacker();
    num = random(100);
        if (num > 93)
	{
		write("Your whip wraps around " +atk->query_cap_name()+ " and %^BOLD%^%^RED%^burns%^RESET%^ them badly!");
		message("attacker", this_player()->query_cap_name() + "'s whip wraps around you, %^BOLD%^%^RED%^burning%^RESET%^ you badly!", atk);
		message("room", this_player()->query_cap_name() + "'s whip wraps around " +atk->query_cap_name()+
		  " %^BOLD%^%^RED%^burning%^RESET%^ them!", environment(this_player()), ({ this_player(), atk }) );
        		
        attack = ((this_player()->query_skill("flail") / 4) - random(this_player()->query_skill("flail") / 7));	
		if (attack < 30)
		{
		  attack = 30;

		}
        return attack;
	}
	
	return 0;   

}	

int query_auto_load(){
    if (this_player()->query_level() > 35) return 1;
    return 0;
}
