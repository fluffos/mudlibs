//hua.c 百香花
inherit ITEM;
#include <ansi.h>

//void init()
//{
//	add_action("do_eat", "eat");
//}

void create()
{
	set_name(HIG"百香花"NOR, ({"hua", "baixiang"}));
	set("unit", "朵");
	set("long", "这是一朵鲜艳的花，花香浓郁异常。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="hua")
	{
//		me->add("max_neili",5);
//		me->unconcious();
		destruct(this_object());
	}
	return 1;
}

