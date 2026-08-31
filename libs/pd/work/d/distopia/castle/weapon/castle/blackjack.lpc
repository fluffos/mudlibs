#include <std.h>
#include <discastle.h>
inherit WEAPON;
int weapon_hit(object atk);
create()
{
	::create();
	set_id(({"blackjack", "blunt"}));
	set_name("blackjack");
	set_short("Blackjack");
	set_long("This seems to be a fairly decent weapon to smack someone over the head with.");
	set_weight(12);
	set_curr_value("gold",120);
    set_wc(5);
	set_type("blunt");
	set_hands(1);
	set_wield("You %^RED%^%^BOLD%^SMACK%^RESET%^ the rubber into your hand, loving the way it sounds.");
	set_unwield("The work done you leave behind the weapon at the scene of the crime");
	set_ac(1);
	set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
	int result;
    if(random(100) > 97)
	{
		write("%^GREEN%^%^BOLD%^You %^WHITE%^SMACK%^GREEN%^ your victim over the head.  Knocking him senseless.");
		say((string)"You wince as "+this_player()->query_cap_name()+" smacks his victim hard on the head.");
        result = random(this_player()->query_level());
		return result;
        atk->set_paralyzed(random(2));
		
	}
}
int query_auto_load() 
{
if(this_player()->query_subclass() != "thug") return 0;
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
	if (this_player()->query_class() != "rogue")
	{
		message("info", "Only those with experiance in thievery may use this.", this_player());
		return 1;
	}
	return 0;
}
