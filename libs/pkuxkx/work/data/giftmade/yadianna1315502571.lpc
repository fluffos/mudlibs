// toy2.c	玩具(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"狮子山传说"+ NOR, ({ "book" }));
	set("long","这是一本小说，署名你的崇拜者宇宙心灵\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_drop", 1);
        set("no_store",1);
		set("value",50000);
        set("no_give",1);
		set("owner", "yadianna");
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
	message_vision("$N看着手中的一本小说嚎啕大哭，"天哪这本《狮子山传说》的小说是谁写的呀，写的太好了，太有深度了，我要嫁给他，我一定要嫁给他"\n",this_player());
	return 1;
}

