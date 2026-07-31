
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
	set_name("周天丹", ( {"zhoutian dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一颗周天丹，可以增加1000点当前内力，30秒内限用一次。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 1);
		set("base_value", 10);
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->query_enemy()&&sizeof(filter_array(me->query_enemy(),(: userp :))))
		return notify_fail("正在和玩家对手战斗，不能使用"+ name() +"。\n");

	if (time()-me->query("last_zhoutian") < 30)
		return notify_fail("慢点吃，别噎着。\n");

	if (me->query("meili") >= me->query("max_neili"))
		return notify_fail("你现在不需要服用"+ name() +"。\n");
	else
	{
		me->add("neili",1000);

		message_vision("$N服下一" + query("unit") + name() + "，顿时内息顺畅许多。\n", me);
		me->start_busy(1);
		me->set("last_zhoutian",time());
		add_amount(-1);

		return 1;
	}

}
