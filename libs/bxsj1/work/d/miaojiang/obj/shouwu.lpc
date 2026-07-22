// shouwu.c 何首乌
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
	set_name(GRN"何首乌"NOR, ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵初具人形的何首乌。\n");
		set("value", 10000);
	}
	setup();
}

 
int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if (me->query_condition("medicine")) {
        me->add("max_neili", -5);
		message_vision(
			HIR "$N吃下一株何首乌，只觉浑身发涨，气血翻涌。\n"
			"原来服食太急太多，药效适得其反！\n" NOR, this_player());
	} else {
	     me->add("max_neili", 1);
               
		message_vision(
			HIG "$N吃下一棵何首乌，顿时间觉得全身充满了活力 !\n" NOR, me);
		me->apply_condition("medicine", 30);
	}
	destruct(this_object());
	return 1;
}
