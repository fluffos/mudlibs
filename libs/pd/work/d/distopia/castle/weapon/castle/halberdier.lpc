#include <std.h>
#include <hermes.h>
#include <rest.h>
inherit WEAPON;
int weapon_hit(object atk);
create()
{
	::create();
	set_id(({"halberdier", "projectile"}));
	set_name("halberdier");
	set_short("Halberdier");
	set_long("This long pole weapon has a rather sharp and nasty axe on the end of it");
	set_weight(30);
	set_curr_value("gold",100+random(40));
	set_wc(12);
	set_type("projectile");
	set_hands(2);
	set_wield("You slice through the air with a few practice swings");
	set_unwield("You %^BOLD%^slam %^RESET%^the blade down into the ground and leave it");
	set_ac(1);
	set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
	int result;
	if(random(100) > 90) 
	{
		write("%^BOLD%^You manage to get into a good position and horribly %^YELLOW%^slice %^WHITE%^into the enemy");
		say((string)"%^BOLD%^"+this_player()->query_cap_name()+"'s %^GREEN%^SLAMS%^WHITE%^ his halberdier into his foe");
		result = (random(160) + ((this_player()->query_level())*(3/5)));
                if(random(100) > 80) 
		{
			write("%^BLACK%^%^BOLD%^You %^RED%^sweep %^BLACK%^your foe off their feet\n");
			say("%^BOLD%^SWEEPS his foe off their feet");
                        atk->set_paralyzed(1, "You are stunned from the fall.");
                        atk->set_rest_type(SIT);
                        return result/4;
		}
	}
}
int query_auto_load() 
{
if(this_player()->query_level() < 30) return 0;
 return 1; 
}
