
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
	set_name(HIC"沧海丹"NOR, ( {"canghai dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "可以完全恢复自身伤势以及内力，可重复使用。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("yuanbao", 2000);
		set("base_value", 2000);
		set("no_sell", 1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	 if (me->is_fighting()) 
		return notify_fail("你现在正在战斗！\n");

	//if( me->query_condition("medicine")>0 )
	//	return notify_fail("你上一次服药的药性还没有过呢！\n");

	me->set("neili",me->query("max_neili")*2);
	me->set("eff_qi",me->query("max_qi")+me->query_gain_qi());
	me->set("qi",me->query("eff_qi"));
	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("eff_jing"));

	message_vision("$N服下一" + query("unit") + name() + "，顿时伤势痊愈了。\n", me);
	//me->apply_condition("medicine",1);
	//me->start_busy(1);

	return 1;
}
