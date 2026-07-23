// xueliandan.c 雪莲丹

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
	set_name("雪莲丹", ({"xuelian dan", "xueliandan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗密制的雪莲丹，散发出一股淡淡的清香，乃是从数株雪莲中提炼萃取而来。\n");
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
		me->add("max_jingli", -10);
		message_vision(HIR "$N吃下一颗雪莲丹，只觉得满嘴枯涩，舌头发紧，七窍生烟，原来所练内功不符，反而大损真元！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("neili_drug" ) > 0 )
	{
		me->add("eff_jingli", -1);
		message_vision(HIR "$N吃下一颗雪莲丹，只觉得味如嚼蜡，精神反而不如以前，原来服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		me->add("eff_jingli", 1);
		message_vision(HIG "$N吃下一颗雪莲丹，只觉得自内向外一股香气沁人心脾，精神为之一振!\n" NOR, me);
	}

	me->apply_condition("neili_drug", 15);
	
	destruct(this_object());
	return 1;
}

