// z-dan.c
// 星星(lywin)炼丹任务附属道具
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
	set_name("大还丹", ({"ndan1", "dan1"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗大还丹。\n");
		set("value", 3000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query("max_neili") < 200 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗大还丹，只觉得头重脚轻，摇摇欲倒，原来功力不够，药效适得其反！\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N吃下一颗大还丹，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
        me->add("neili", 200);
        message_vision(HIG "$N吃下一颗大还丹，只觉得体内的的内力加了不少!\n" NOR, me);
	}

        me->apply_condition("medicine", 20);
	
	destruct(this_object());
	return 1;
}