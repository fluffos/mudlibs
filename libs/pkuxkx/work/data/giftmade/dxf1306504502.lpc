// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY +"百事可乐"+ NOR, ({ "cola" }));
	set("long","这是一瓶百事可乐。\n;冰凉的瓶身上还挂着冰珠，让人禁不住想来上一口。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "dxf");
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
	message_vision("$N擦了擦头上的汗珠，拿起一瓶凝着冰珠的百事可乐，咕咚咕咚地大口喝了起来。真爽快啊！\n$N只觉得精神一振，忍不住从心底发出了赞叹：可乐果然还是要喝百事的！\n",this_player());
	return 1;
}

