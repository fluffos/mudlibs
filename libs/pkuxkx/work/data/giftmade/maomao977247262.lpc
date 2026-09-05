// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM +"凤凰琴"+ NOR, ({ "qin" }));
	set("long","只见你手中青虹剑急颤，幻出满天剑芒，无数剑气有如百鸟投林般向达摩扑去!达摩躲闪不及，身上三处中了剑气!\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
                set("no_sell",1);
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "maomao");
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
	message_vision("只见$N手中凤凰琴急颤，幻出满天剑芒，无数剑气有如百鸟投林般向达摩扑去达摩躲闪不及，身上三处中了剑气\n",this_player());
	return 1;
}

