// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW +"小萌兔"+ NOR, ({ "tutu" }));
	set("long","一直莹白色的小兔子。好像是刚才从月亮上掉下来的！它正躺在你的手心上，绒绒萌萌的，让人忍不住想摸摸。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "atgw");
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
	message_vision("$N轻轻摸了摸小兔子，小兔子凑得更近了点。\n 这时候，银色的月光温柔地洒进了窗子。\n “嘭”的一声，一阵烟雾过后，小兔子变成了一个美丽的小公主。\n",this_player());
	return 1;
}

