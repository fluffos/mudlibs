// z-dan.c
// 星星(lywin)炼丹任务附属道具
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "chi");
}

void create()
{
	set_name("回阳膏", ({"neilidan", "neilidan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗回阳膏。你可以用chi来吃它。\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

        if(me->is_busy())
        return notify_fail("你现在正忙，没法吃东西。\n");

        if(!me->is_fighting())
        return notify_fail("回阳膏是在站斗中急用的！\n");

        if( (int)me->query("neili") * 100 / (int)me->query("max_neili") >= 40)
        return notify_fail("你现在内力还多着呢！\n");

	if ( me->query("max_neili") < 600 )
	{
        me->add("neili", 1);
		message_vision(HIR "$N吃下一颗回阳膏，只觉得头重脚轻，摇摇欲倒，原来功力不够，药效适得其反！\n" NOR, me);
	}
            else if ( (int)me->query_condition("neilidan") > 0 )
	{
        me->add("neili", 1);
		message_vision(HIR "$N吃下一颗回阳膏，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
        me->add("neili", me->query("max_neili")/2);
        message_vision(HIG "$N吃下一颗回阳膏，只觉得体内真力源源滋生，你的内力提高了!\n" NOR, me);
	}

        me->apply_condition("neilidan", 2);
	
	destruct(this_object());
	return 1;
}