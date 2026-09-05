// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"白菜碗"+ NOR, ({ "bowl" }));
	set("long","这是白菜当乞丐是随身自带的碗,用了多年,也算是一件传家之宝了\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "hail");
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
	message_vision(" $N拿起白菜碗,大叫一声:"白菜何在?"\n一阵烟雾过后,碗中站起一人,正是白菜.\n$N看了看,叹口气:"可惜只是个木偶,不是真的白菜大哥呀!"\n",this_player());
	return 1;
}

