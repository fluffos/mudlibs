#include <std.h>
inherit OBJECT;

object owner;

void create() {
    ::create();

    set_name("morph_object_1x3");
    set_heart_beat(1);
    set_short("");
    set_long("morph object");
    set_weight(0);
    set_value(0);
    set_id(({"morph_object_1x3"}));
}

void object_gone()
{
    this_object()->remove();
}

void heart_beat()
{
    if(!environment(this_object())) return;
    if((!owner) && (environment(this_object())->is_living()))
        owner = environment(this_object());
    if(!owner)
    	return;
    
    owner->add_mp(-(5+random(5)));
    
    if(owner->query_mp() < 0)
    {
		owner->force_me("morph");	
	}
}

void init() {
	::init();
                add_action("prevent_a", "eagleblitz");
                add_action("prevent_a", "freeze");
                add_action("prevent_a", "thorns");
                add_action("prevent_a", "vinegrasp");
                add_action("prevent_a", "whirlwind");
                add_action("prevent_a", "bearsrage");
                add_action("prevent_a", "felinefury");
                add_action("prevent_a", "foxeswit");
                add_action("prevent_a", "husk");
                add_action("prevent_a", "owlsmind");
                add_action("prevent_a", "rootgrasp");
                add_action("prevent_a", "hold");
                add_action("prevent_a", "light");
                add_action("prevent_a", "scry");
                add_action("prevent_a", "shoot");
                add_action("prevent_a", "tame");
                add_action("prevent_a", "fortitude");
                add_action("prevent_a", "vinearmour");
                add_action("prevent_a", "peace");
                add_action("prevent_a", "sense");
	            add_action("prevent_a", "scry");
				add_action("prevent_a", "resonate");
				add_action("prevent_a", "fly");
				add_action("prevent_a", "holyfire");
				add_action("prevent_a", "levin");
}

int prevent_a(string str)
{
	write("You can not do that in this form!");	
	return 1;
}
