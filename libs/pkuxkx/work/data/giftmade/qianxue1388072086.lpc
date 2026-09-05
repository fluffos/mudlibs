// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM +"粉红小猪"+ NOR, ({ "pinkypiggy" }));
	set("long","这是一只巴掌大的粉红色的小猪，正趴在你的手心呼呼大睡。\n\n");
	set_weight( 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "qianxue");
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
	message_vision("小猪正在睡觉，呼噜打的震天响。\n小猪舔了舔自己的鼻子。\n你用手指戳了戳小猪，小猪用蹄子把你蹬了回去。\n小猪打了个嗝，扭动着自己的腰肢。\n小猪迷瞪瞪的瞅了你一眼，又赶紧用耳朵遮住。\n小猪正在睡觉，呼噜大的震天响。\n",this_player());
	return 1;
}

