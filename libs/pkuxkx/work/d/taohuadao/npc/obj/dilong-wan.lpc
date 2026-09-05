// dilong-wan.c 通犀地龙丸

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
       set_name("通犀地龙丸",({"dilong wan","wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
       set("unit","粒");
       set("long","这是一粒通犀地龙丸，乃当年西毒欧阳锋来此处时"
"留下的，有解毒的功能。\n");
		set("value", 10000);
		set("no_drop", "这样东西不能离开你。\n");
	}

       set("taohuadao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	int i;
	i=me->query("max_jing");
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	if(me->query("jing")>=me->query("max_jing"))
	return notify_fail("你现在不需要通犀地龙丸。\n");
	else
	{
		me->set("jing", i);
	 message_vision(HIG"$N吃下一粒通犀地龙丸，顿觉体内毒气慢慢消去，精神好多了。\n"NOR,me);
	}
        
       	
	destruct(this_object());
	return 1;
}

