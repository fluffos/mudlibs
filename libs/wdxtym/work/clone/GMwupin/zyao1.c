
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
	set_name("天王保命丹", ( {"baoming dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一颗天王保命丹，可以完全恢复自身伤势。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 90000);
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

if (sizeof(filter_array(me->query_enemy(),(: userp :))))
		return notify_fail("正在和玩家对手战斗，不能使用"+ name() +"。\n");

	if (me->query("eff_qi")*100/ (me->query("max_qi")+me->query_gain_qi())>99 && me->query("eff_jing")*100/ me->query("max_jing")>99)
		return notify_fail("你现在不需要服用"+ name() +"。\n");
	else
	{
		if( me->query_condition("medicine")>0 )
			return notify_fail("你上一次服药的药性还没有过呢！\n");

		me->set("eff_qi",me->query("max_qi")+me->query_gain_qi());
		me->set("eff_jing",me->query("max_jing"));

		message_vision("$N服下一" + query("unit") + name() + "，顿时伤势痊愈了。\n", me);
		me->apply_condition("medicine",4);
		me->start_busy(2);
		if (query_amount() < 2) write("你的"+ name() +"用完了。\n");
		add_amount(-1);
		return 1;
	}

}
