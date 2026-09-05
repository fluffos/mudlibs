// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"翡翠白菜"+ NOR, ({ "baicai" }));
	set("long","这是一颗Cabbage按自己的样子雕成的翡翠白菜。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "yinying");
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
	message_vision("$N拿起翡翠白菜，随手按下了开关。\n翡翠白菜抽出腰间的白菜帮子，使出一套打icer棒法。\n$N看完不由得赞道：“好棒法！”然后想了想又说：“不过要是真的白菜大哥会更好！”\n",this_player());
	return 1;
}

