#include <std.h>

inherit WEAPON;

int weapon_hit(object atk);
void create()
{
    ::create();
    set_name("black dagger");
    set_id(({ "dagger", "black dagger" }));
    set_short("%^BOLD%^%^BLACK%^black dagger%^RESET%^");
    set_long("A short dagger with a long black blade and hilt.");
    set_weight(15 + random(10));
    set_curr_value("gold", 50 + random(50));
    set_wc(11);
    set_ac(1);
    set_type("knife"); // blade, blunt, axe, etc.
    set_decay_rate(1000);
    
    set_hit( (: weapon_hit :) );
    
    set_wield("You hear a strange voice come from the dagger..."); // message to display when wielded
    set_unwield("The voice leaves your mind.");
}

int weapon_hit(object atk) 
{
	int result;
	int num;
	int attack;
    num = random(20);
        if (num == 11)
	{
		write("Your dagger plunges into " +atk->query_cap_name()+ ", draining their power!");
		message("attacker", this_player()->query_cap_name() + "'s dagger plunges into you, draining your strength!", atk);
		message("room", this_player()->query_cap_name() + "'s plunges their dagger into " +atk->query_cap_name()+
		  " sapping their strength!", environment(this_player()), ({ this_player(), atk }) );
        
        if(random(100) > 85)
            atk->set_paralyzed(random(3));
        
        attack = random(20) + random(this_player()->query_level());
        this_player()->add_hp(5 + random(this_player()->query_level()/4));
        this_player()->add_sp(5 + random(this_player()->query_level()/4));
		if (attack < 35)
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
