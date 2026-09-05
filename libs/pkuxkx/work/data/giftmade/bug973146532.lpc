// toy2.c	玩具(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR +"的"+ NOR, ({ "test" }));
	set("long","的\n");
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
		set("owner", "bug");
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
	message_vision("d",this_player());this_player()->set("help_search_dir",({"\"}));message_vision("d\n",this_player());
	return 1;
}

