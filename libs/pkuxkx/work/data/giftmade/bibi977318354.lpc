// toy2.c	玩具(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"八音盒"+ NOR, ({ "musicbox" }));
	set("long","这是一件钢琴形状的八音盒。\n里面是双儿最喜欢的音乐。\n\n");
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
		set("owner", "bibi");
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
	message_vision("d\n",this_player( this_player(->add("max_neili",300message_vision("d\n",this_player());
	return 1;
}

