// xionghuangjiu.c
// Lklv modify

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "drink");
	add_action("do_eat", "he");
	add_action("do_eat", "yin");
}

void create()
{
	set_name(HIG "雄黄酒" NOR, ({"xionghuangjiu","jiu","skin"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是一碗雄黄酒，是神龙教弟子入教时必喝(drink)的，据说可以防蛇咬。\n");
		set("unit", "碗");
		set("no_get", 1);
		set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();

	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;

	if (me->query("family/family_name") != "神龙教"){
		message_vision(HIG "$N吃下一碗雄黄酒，顿时觉得腹部痛如刀绞。\n"NOR,me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	if (me->query("xionghuangjiu")){
		message_vision(HIG "$N吃下一碗雄黄酒，顿时觉得腹部痛如刀绞。\n"NOR,me);
		me->add("max_neili", -5);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	message_vision(HIG "$N吃下一碗雄黄酒，顿时觉得全身发热，一股酒气直冲头顶。\n"NOR,me);
	me->set("xionghuangjiu",1);
	me->add("max_neili", 1);
	me->start_busy(1);
	destruct(this_object());
	return 1;
}
