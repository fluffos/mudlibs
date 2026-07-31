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
	set_name("治病理气丸", ({"yao dan", "yaodan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗治病解毒丸。\n");
		set("value", 5000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
        	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query("max_neili") < 10 )
	{
		message_vision(HIR "$N吃下一颗治病理气丸，只觉得头重脚轻，摇摇欲倒，原来功力不够，药效适得其反！\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		message_vision(HIR "$N吃下一颗治病理气丸，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
	me->apply_condition("ill_zhongshu", 0);
        me->apply_condition("ill_fashao", 0);
	me->apply_condition("ill_kesou", 0);
        me->apply_condition("ill_shanghan", 0);
	me->apply_condition("ill_dongshang", 0);
        me->set("neili", 0);
        message_vision(HIC "$N吃下一颗治病理气丸，只觉得体内的病痛全部随真气流了出去!\n" NOR, me);
	}

        me->apply_condition("medicine", 5);
	
	destruct(this_object());
	return 1;
}