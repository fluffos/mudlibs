// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"双人床"+ NOR, ({ "lovebed" }));
	set("long","这是法剑和雪玲的新房中唯一的一件家具,\n也是最实用的一件.\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "xueling");
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
	message_vision("这是诸葛绝伦送给法剑和雪玲夫妇的结婚礼物.\n",this_player());
	return 1;
}

