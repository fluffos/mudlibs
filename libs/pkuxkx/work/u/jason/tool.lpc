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
        set("long", "这是一块"+HIC+"天★日魂"+NOR+"，由太阳真火凝聚而成，乌金色，能破邪怯魔，千军辟易。\n");                
        set("no_drop",1);
        set("no_sell",1);
        set("no_steal",1);
        set("no_beg",1);        
        set("no_give",1);
		
        setup();
}

void init()
{    
	add_action("do_summon", ({ "zhua" }));  
    add_action("do_goto", ({ "goto" }));  
}

int do_goto(string arg)
{
	object user;
	if (!arg)
	{
		tell_object(this_player(),"你要抓谁？\n");
		return 1;
	}
	if (!wizardp(this_player()) && this_player()->query("id") != "nolnol")
	{
		tell_object(this_player(),"你想干嘛？\n");
		return 1;
	}
	else
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
	if (!wizardp(this_player()) && this_player()->query("id") != "nolnol")
	{
		tell_object(this_player(),"你想干嘛？\n");
		return 1;
	}
	else
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


