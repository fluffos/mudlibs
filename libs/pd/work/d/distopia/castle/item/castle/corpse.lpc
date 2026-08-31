#include <discastle.h>
#include <std.h>
inherit OBJECT;
int antipara, paralength;
void init()
{
	::init();
	add_action("sac","sacrifice");
	add_action("sac","feed");
	add_action("sac","butcher");
	add_action("sac","offer");
	add_action("sac","eat");
}
void create() 
{
	::create();
    set_name("corpse");
    set_short("The corpse of Rich Merchant");
    set_long("This is the dead body of Rich Merchant. It contains:\n   800 gold");
    set_prevent_get
    (
		"You would not touch the bloodied remains!"
    );
    set_id(({"corpse"}));
}
int sac(string str)
{
	if (!str)
	{
		write("What?");
		return 1;
	}
	if (str == "corpse")
	{
		write("%^BOLD%^A trap %^RED%^SPRINGS%^WHITE%^ up around you, lifting you high in the air!\n");
		tell_object(environment(this_object()),"\n" + this_player()->query_cap_name() + " yelps as " + this_player()->query_subjective() + " is lifted into the air by a giant net!\n");
		new(MOB"bandit")->move(environment(this_object()));
		new(MOB"bandit")->move(environment(this_object()));
		new(MOB"bandit")->move(environment(this_object()));
		
	    tell_object(environment(this_object()),"\nSuddenly, three bandits appear out of the woods, their intention clear as they unsheath their daggers and move to their helpless pray.\n");
		antipara = (int)this_player()->query_stats("strength") + (int)this_player()->query_stats("dexterity");
		paralength = 0;
		if (antipara <= 160)
			paralength = 1;
		if (antipara <= 140)
			paralength = 2;
		if (antipara <= 120)
			paralength = 3;
		if (antipara <= 100)
			paralength = 4;
		this_player()->set_paralyzed(paralength, "You are trying to break free of the net.");       
		this_object()->remove();
		return 1;
	}
}
