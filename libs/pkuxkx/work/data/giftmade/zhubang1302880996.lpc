// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"竹棒"+ NOR, ({ "club" }));
	set("long","这是一根普通的竹棒，但是你隐隐觉得它有不平凡的魅力。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "zhubang");
		set("auto_load", 1);
		set("material", "gold");
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
	add_action("do_play","play");
}

int do_play(string arg)
{
	if (!arg || arg!=query("id"))
	{
		write("你要玩什么？\n");
		return 1;
	}
	message_vision("竹棒突然断成两截。$N突然打了个筋斗，大叫：哼哼哈嘿，快使用双截棍！哼哼哈嘿，仁者无敌！\n$N疯了……\n\n",this_player());
	return 1;
}

