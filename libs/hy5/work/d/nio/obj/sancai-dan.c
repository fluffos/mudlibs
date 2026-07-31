// /u/jpei/thd/obj/sancai-dan.c 三才聚精丹 

#include <ansi.h>

inherit ITEM;

void setup() {}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("三才聚精丹", ({"sancai dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒碧绿色的丹药，透出一股浓重的花香。\n");
		set("value", 100);
                set("no_drop", 1);
                set("no_get", 1);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if ( me->query("family/family_name") != "桃花岛" )
	{
/*		if (me->add("max_jingli", -10) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -10) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N服下一粒三才聚精丹，只觉得头痛欲裂，原来竟是一颗假药！\n" NOR, me);
		me->unconcious();
		destruct(this_object());
*/    
		message_vision(HIR "所练内功不符，这药你不能随便吃！\n" NOR, me);
		return 1;
	}
	if ( (int)me->query("max_jingli" ) < 200) {
		message_vision(HIR "功力不够，灵药吃了有害无宜。\n" NOR, me);
		return 1;
	}
	

	if ( (int)me->query_condition("jingli_drug" ) > 0 )
	{
		if (me->add("max_jingli", -1) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -1) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N服下一粒三才聚精丹，只觉得头晕目眩，意乱神迷，原来灵药服食太急太多，药效适得其反！\n" NOR, me);
	}
	else
	{
		me->add("max_jingli", 1);
		me->add("eff_jingli", 1);
		message_vision(HIG "$N服下一粒三才聚精丹，只觉得体内精力充溢，似乎有使不完的劲！\n" NOR, me);
		me->apply_condition("jingli_drug", 60);
	}
	destruct(this_object());
	return 1;
}
