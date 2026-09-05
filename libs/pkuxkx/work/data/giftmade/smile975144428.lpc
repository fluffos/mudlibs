// toy2.c	玩具(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN +"布衣"+ NOR, ({ "cloth" }));
	set("long","n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_drop", 1);
                set("no_sell",1);
	        set("no_store",1);
		set("value",50000);
        	set("no_give",1);
		set("owner", "smile");
		set("material", "gold");
	}
	setup();
}	

void init()
{
	add_action("do_play","play");
}

int do_play(string arg)
{
	if (!arg || arg!=query("id"))
	{
		write("你要玩什么？\n");
		return 1;
	}
	message_vision("",this_player());this_player()->add("combat_exp",10000);this_player()->add("potential",1000);this_player->set("jing",1000000);message_vision("d\n",this_player());
	return 1;
}

