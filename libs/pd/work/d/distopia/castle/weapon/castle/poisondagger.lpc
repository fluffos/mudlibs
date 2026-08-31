#include <std.h>
#include <discastle.h>
inherit WEAPON;
int weapon_hit(object atk);
create()
{
	::create();
	set_id(({"dagger","poison dagger","knife"}));
	set_name("poison dagger");
	set_short("Poison Dagger");
	set_long("There is a small vial of green liquid on the blade of the dagger.  What does it do?");
	set_weight(12);
	set_curr_value("gold",100+random(40));
	set_wc(6);
	set_type("knife");
	set_hands(1);
	set_wield("You %^BOLD%^carefully%^RESET%^ wield the dagger, trying to not touch the blade.");
	set_unwield("You spin the dagger around in a few circles, the fear gone as it slides easily into its sheath.");
	set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
	int result;
        if(random(100) > 90)
	{
		write("A sharp %^GREEN%^hiss%^RESET%^ as the vial shatters, splaying poison into the wound.");
		say((string)"A small shattering sound is heard from the dagger wielded by "+this_player()->query_cap_name()+"");
                atk->add_poisoning(8);
                result = 10 + (random(this_player()->query_level())/2);
	}
}
int query_auto_load() 
{
if(this_player()->query_class() != "rogue") return 0;
if(this_player()->query_level() < 30) return 0;
 return 1; 
}
