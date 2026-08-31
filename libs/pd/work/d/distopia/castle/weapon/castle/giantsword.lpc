
#include <std.h>
#include <rest.h>
inherit WEAPON;
int weapon_hit(object atk);
create()
{
	::create();
	set_id(({"giant sword", "sword", "blade", "giant"}));
	set_name("giantsword");
	set_short("Giant Sword");
	set_long("This sword is MASSIVE! You could never hope to lift it unless you were one of the huge giants.");
	set_weight(90);
	set_curr_value("gold",100+random(40));
        set_wc(14);
	set_type("blade");
	set_hands(2);
	set_wield("You grunt but manage to lift the giant sword up.");
	set_unwield("You release the sword, letting it drop to the earth, the ground shakes.");
        set_ac(2);
	set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
	int result;
        if(random(100) > 90)
	{
		write("You %^BOLD%^smack%^RESET%^ your opponent with the flat end, sending him sprawling!");
		say((string)""+this_player()->query_cap_name()+" smacks his opponent with the flat end, sending him flying to the ground.");
		atk->set_rest_type( SIT );
		if (random(100) > 50)
		{
			atk->set_paralyzed(1);
		}
                result = (10 + random(40));
	}
	return 1;
}
int query_auto_load() 
{
if(this_player()->query_race() != "giant") return 0;
if(this_player()->query_level() < 30) return 0;
 return 1; 
}
void init()
{
	::init();
	add_action("wielder","wield");
}
int wielder(string willitwield)
{
	object ob;
	if (!willitwield)
		return 0;
	ob = present(willitwield, this_player());
	if (ob != this_object())
		return 0;
	if (this_player()->query_race() != "giant")
	{
		message("info", "You struggle, but can not even begin to lift this massive blade", this_player());
		return 1;
	}
	return 0;
}
