inherit WEAPON;
int weapon_hit();
int result = 0;
int chance;
int level;
int moo;
int moo1;
int count = 0;
create()
{
	::create();
	set_id(({"knife", "crys knife"}));
	set_name("crys knife");
	set_short("%^BOLD%^C%^RESET%^r%^BLACK%^%^BOLD%^y%^RESET%^s %^BLACK%^%^BOLD%^K%^RESET%^n%^BOLD%^i%^BLACK%^%^BOLD%^f%^RESET%^e");
	set_long("The Crys Knife is a mystical blade made out of an unknown crystaline metal.  The knife was forged by the Gods in their war against evil and used in the holy crusade against the demons.  The knife streams with power and glows brightly.");
	set_weight(10);
	set_curr_value("gold",8000+random(40));
	set_wc(18);
	set("skill level", 250);
	set_type("knife");
	set_hands(1);
	set_wield("%^BOLD%^A burst of power %^RED%^EXPLODES%^WHITE%^ into your body!");
	set_unwield("The power fades leaving you drained.");
	set_ac(1);
	set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit()
{
	if(random(100) > 90) 
	{
		object atk;
		chance = (this_player()->query_stats("strength") + this_player()->query_stats("dexterity"));
		level = (this_player()->query_level());
		moo = (chance - level);
		do
		{
			++count;
		}while(level < random(chance));
		if (count > 10)
		{
			count = 10;
		}
		if (count == 0)
		{
			count = 1;
		}
		
		atk = (object)this_player()->query_current_attacker();
		atk->set_paralyzed(count / 2);
		write("You release a wild %^YELLOW%^%^BOLD%^YELL%^RESET%^ as you start the %^GREEN%^%^BOLD%^Crys Chain%^RESET%^");
		say((string)"A blinding flash from the knife is seen as a Crys Chain is started.");
		this_player()->set_paralyzed((count / 4),"You are concentrating fully on the Crys Chain!");
		if(!atk->is_monster())
		{
			return;
		}
		moo1 = moo;
		hit();
		return result;
	}
}
int query_auto_load() 
{
	if(this_player()->query_level() < 50) return 0;
	return 1; 
}
void hit()
{
	
	--count;
	if(count < 0)
	{
		return;
	}
	moo = moo1;
	moo = random(moo);
	
		if (moo < 0)
		{
			write("You miss, but continue the chain anyway!");
		
		}
		
		if (moo > 0 && moo < 30)
		{
			write("You nick your opponent!");
			result = result + 50;
		}
		
		if(moo > 30 && moo < 70)
		{
			write("You cut your victim!");
			result = result + 75;
		}
		
		if(moo > 70 && moo < 100)
		{
			write("You slash your victim!");
			result = result + 150;
		}
		
		if(moo > 100)
		{
			write("%^RED%^%^BOLD%^The knife %^GREEN%^hums%^WHITE%^ as it sinks through flesh and bone");
			result = result + 235;
		}
		hit();
}
