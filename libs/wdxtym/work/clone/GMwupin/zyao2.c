
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload()
{
	return query_amount() + "";
}

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name("生生造化丹", ( {"zaohua dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一颗生生造化丹，可以补满自己的当前内力。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 1);
		set("base_value", 50000);
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->query_temp("dgjj/zongjue"))
		return notify_fail("你目前的状态无法使用"+ name() +"。\n");

	if (me->query_enemy()&&sizeof(filter_array(me->query_enemy(),(: userp :))))
		return notify_fail("正在和玩家对手战斗，不能使用"+ name() +"。\n");

	if (me->query("neili")> me->query("max_neili"))
		return notify_fail("你现在不需要服用"+ name() +"。\n");
	else
	{
		if( me->query_condition("medicine")>0 )
			return notify_fail("你上一次服药的药性还没有过呢！\n");

		me->set("neili",me->query("max_neili")*2);

		message_vision("$N服下一" + query("unit") + name() + "，顿感真气充盈。\n", me);
		me->apply_condition("medicine",4);
		me->start_busy(2);
		if (query_amount() < 2) write("你的"+ name() +"用完了。\n");
		add_amount(-1);
		return 1;
	}

}
