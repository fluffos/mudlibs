#include <ansi.h>
inherit ITEM;	

void create()
{
        set_name(HIC"天★日魂"NOR,({ "tian ri","gem"}) );
        set_weight(4000);
        set("unit", "块");
        set("value", 1);
        set("material", "steel");
        set("auto_load", 1);
        set("long", "这是一块"+HIC+"天★日魂"+NOR+"，由太阳真火凝聚而成，乌金色，能破邪怯魔，千军辟易。(zhua,goto,halt)\n");                
        set("no_drop",1);
        set("no_sell",1);
        set("no_steal",1);
        set("no_store",1);
        set("no_beg",1);        
        set("no_give",1);
        set("no_get_from",1);
        setup();
}

void init()
{
    if (!wizardp(this_player()) && this_player()->query("newbie_guider"))    
    {
        add_action("do_summon", ({ "zhua" }));  
        add_action("do_goto", ({ "goto" }));  
        add_action("do_halt", ({ "halt" }));  
    }
}

int do_halt()
{
    if(this_player()->is_fighting())
    {
        this_player()->remove_all_enemy();
        write("你大喊一声，住手！大家都不敢打你了。\n");
    }
    return 1;
}
int do_goto(string arg)
{
	object user;
	if (!arg)
	{
		tell_object(this_player(),"你要去哪？\n");
		return 1;
	}
    if (arg=="zine")
    {
        tell_object(this_player(),"此人现在所处的位置，不似凡间，你不能跟踪。\n");
        return 1;
    }
	{
		user=find_player(arg);
		if(objectp(user) && objectp(environment(user)))
		{
			this_player()->move(environment(user));
			tell_object(user,HIG"你眼前一亮，来到了"+environment(this_player())->query("short")+"\n"NOR);
		}
		return 1;
	}
}

int do_summon(string arg)
{
	object user;
	if (!arg)
	{
		tell_object(this_player(),"你要抓谁？\n");
		return 1;
	}

	{
		user=find_player(arg);
		if(objectp(user))
		{
			user->move(environment(this_player()));
			tell_object(user,HIG"你眼前一亮，来到了"+environment(this_player())->short()+"\n"NOR);
		}
		return 1;
	}
}


