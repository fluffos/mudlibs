// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW +"香菜"+ NOR, ({ "xiangcai" }));
	set("long","白菜和丽香的女儿\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "cabbage");
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
	message_vision("小香菜抬起头，用乌黑的大眼睛盯着$N，问：“爸爸，妈妈怎么还不回来呀？”\n$N眼圈一红，说：“好孩子，你妈妈在很远的地方，要很久才能回来。”\n小香菜似懂非懂地点点头，说：“我将来要做一个象爸爸一样的大侠，还要象妈妈一样漂亮。”\n小香菜又说：“不过，我还是想妈妈！”\n",this_player());
	return 1;
}

