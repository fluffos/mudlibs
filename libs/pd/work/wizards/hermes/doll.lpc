#include <std.h>
inherit OBJECT;

void init()
{
	::init();
	add_action("sac","summon");
	
}
void create() 
{
	::create();
    set_name("cow doll");
    set_short("A cow doll");
    set_long("This is odd, it's a miniature replica of a cow.  It has a nametag around it that identifies it as belonging to Cookie.");
    set_id(({"doll", "cow doll"}));

}


int sac(string str)
{
	if (!str)
	{
		write("Summon what?");
		return 1;
	}
	if (str == "cow")
	{
		write("%^BOLD%^You summon... A COW\n");
		say("\n" + this_player()->query_cap_name() + " looks at a strange cow figure in his hand, mutters a few words, then looks around expectently. \n");
		new("/wizards/hermes/moocookie")->move(environment(this_object()));
		return 1;
	}
}
int query_auto_load() 
{ 
	if 
	(
		this_player()->query_name() == "cookie") 
		return 1; 
	}
