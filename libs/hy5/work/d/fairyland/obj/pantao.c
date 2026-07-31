// pantao.c 蟠桃
// By jpei

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("蟠桃", ({"peach", "pantao", "pan tao", "tao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚拳头大小的蟠桃。\n");
		set("value", 300);
	}
	setup();
}

void init()
{
	add_action("do_eat", ({"eat", "chi"}));
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg)) return notify_fail("你要吃什么？\n");

	if (me->query_condition("bonze_drug")) {
		message_vision("$N吃下一枚蟠桃，似乎不那么饥饿了。\n", me);
		if (me->query("food") < me->max_food_capacity())
			me->add("food", 30);
	}
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N吃下一枚蟠桃，体内的真气似乎有些鼓动。\n" NOR, me);
		me->apply_condition("bonze_drug", 200);
	}
	destruct(this_object());
	return 1;
}
