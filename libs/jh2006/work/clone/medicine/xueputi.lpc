// xueputi.c 血菩提

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "fu");
}

void create()
{
	set_name("血菩提", ({"xue puti", "xueputi", "puti"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗传说中的血菩提，从血菩提树上采摘下来没多久。\n");
		set("value", 2000);
		set("no_drop", "这样东西不能离开你。\n");
	}

	set("xueshan",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if ( me->query_skill_mapped("force") != "longxiang-boruo" )
	{
		me->add("max_neili", -10);
		message_vision(HIR "$N吃下一颗血菩提，只觉得如火中烧，气血翻涌，原来所练内功不符，反而大损真元！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("neili_drug" ) > 0 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N吃下一颗血菩提，只觉得舌干唇裂，气血翻涌，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N吃下一颗血菩提，只觉得气血充盈，真气鼓荡，全身功力顿然提高 !\n" NOR, me);
	}

	me->apply_condition("neili_drug", 15);
	
	destruct(this_object());
	return 1;
}

