// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY +"枇杷"+ NOR, ({ "hazama" }));
	set("long","一颗肥肥圆圆的枇杷果实，淡黄中透着隐隐的青色。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "basara");
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
	message_vision("$N将枇杷放到鼻下，嗅到一缕奇妙的生命之味，苦涩却又微甜。\n风卷起$N青色的衣摆，肩上的蜻蛉歪着头好奇地看着$N。\n$N微微一笑，把枇杷放回胸前的锦囊内，仔细地收好。\n\n",this_player());
	return 1;
}

