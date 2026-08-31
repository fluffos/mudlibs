
#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);

void create() {
  ::create();

    set_name("bone club");
    set_id( ({ "Bone club", "club" }) );
    set_short("Bone club");
    set_long("A club carved from the bone of some large creature, perhaps a dragon or dinosaur.");
    set_type("blunt");
    set_wc(10);
    set_weight(73);
    set_curr_value("gold", 5);
    set_hit( (: weapon_hit :) );
}

int weapon_hit(object atk) 
{
    int num, attack;
    num = random(300);
	if (num == 299)
	{
		write("Your bone club explodes into a million pieces, with each piece cutting "+atk->query_cap_name()+"!");
		message("room",this_player()->query_cap_name()+"'s club explodes into a million pieces!",environment(this_player()), ({this_player(),atk}));
        message("target", this_player()->query_cap_name()+"'s club explodes into a million pieces in your face!", atk);	
   	
     	
		attack = (100 + this_player()->query_skill("blunt"));
        this_object()->remove();
        
        return attack;
	}
	
	return 0;   

}



int query_auto_load()
{
    if (this_player()->query_level() > 25) return 1;
    return 0;
}
