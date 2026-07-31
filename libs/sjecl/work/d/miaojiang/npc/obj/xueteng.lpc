//  xueteng 雪藤

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"雪藤"NOR, ({"xue teng", "teng"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "这是一段洁白如玉的雪藤，十分罕见。\n");
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
        	me->set("qi", 0);
        	me->set("jing", 0);

		message_vision(
			HIR "$N吃下一株雪藤，只觉得浑身冰凉，宛如坠如冰窖。\n"
			"原来服食太急太多，药效适得其反！\n" NOR, this_player());
	} else {
	        me->set("eff_qi", me->query("max_qi"));
	        me->set("qi", me->query("max_qi"));
	        me->set("eff_jing", me->query("max_jing"));
	        me->set("jing", me->query("max_jing"));
	        me->set("neili", me->query("max_neili"));
  
		message_vision(
			WHT "$N吃下一株雪藤，只觉得七筋八脉通体清凉！\n" NOR, me);
		me->apply_condition("medicine", 30);
	}
	destruct(this_object());
	return 1;
}
