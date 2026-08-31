#include <std.h>
#include <hermes.h>
inherit WEAPON;
int weapon_hit();
create()
{
	::create();
	set_id(({"warblade", "sword", "blade", "war"}));
	set_name("Warblade");
	set_short("Warblade");
	set_long("The blade shines with gold. Forming a half moon which allows for one who is familer with the type of weapon to emply the weapon with great east against foes.");
	set_weight(30);
	set_curr_value("gold",150+random(40));
	set_wc(13);
	set_type("blade");
	set_hands(1);
	set_wield("You move the half moon in a few circles, rather liking its sophisticated design.");
	set_unwield("You frown as you let go of the hilt, the %^RED%^blood%^RESET%^ stains showing how much you enjoyed using it.");
	set_ac(1);
	set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit()
{
	int result;
	object atk;
	atk = (object)this_player()->query_current_attacker();
	if(random(100) > 90) 
	{
		write("%^GREEN%^%^BOLD%^You must be getting the hang of this.The sword %^BLUE%^slashes%^GREEN%^ one end\n"
		"of your foe and rounds out with another hit to their %^CYAN%^side%^GREEN%^, opening a %^RED%^large %^YELLOW%^wound.");
		say((string)""+this_player()->query_cap_name()+"'s %^YELLOW%^%^BOLD%^Warblade %^GREEN%^slashes his foe %^WHITE%^across the %^RED%^chest before whipping the blade around and sending the other end into his %^BLUE%^side.");
		result = (random(30) + ((this_player()->query_level())*(3/5)));
                if(random(100) > 80)
		{
			write("%^BLUE%^%^BOLD%^You %^RED%^slash %^BLUE%^your foes %^WHITE%^neck%^BLUE%^ then %^CYAN%^whirl%^BLUE%^ around swinging the blade\n"
			"in a %^GREEN%^wild arc%^BLUE%^ to send him off balance.");
			say("%^BOLD%^A wild yell erupts as the warblade %^RED%^SLAMS%^WHITE%^ into the side of the foe, making them stumble.");
			atk->set_paralyzed(3);
			return result;
		}
	}
}
int query_auto_load() 
{
if(this_player()->query_subclass() != "swashbuckler") return 0;
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
	if (this_player()->query_subclass() != "swashbuckler")
	{
		message("info", "The blade slips out of your hands. You do not have the finesse to wield such a finely tuned instrument.", this_player());
		return 1;
	}
	return 0;
}
