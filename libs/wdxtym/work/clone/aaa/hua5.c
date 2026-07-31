
#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

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
	set_name(HIC "翡翠兰" NOR, ({"feicui lan", "feicui", "lan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("base_unit", "朵");
		set("long", "这是一朵千年难得一见的翡翠兰，据说能解百毒。\n");
		set("no_sell", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("yuanbao",20);
		set("value", 500000);
		set("base_value", 500000);
		set("base_weight", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if(me->is_fighting()||me->is_busy())
		return notify_fail("你正在忙着呢！\n");
	me->set_temp("nopoison", 3);
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	message_vision("$N把" + name() + "扔进嘴里，几下就吞了下去。\n", me);
	tell_object(me, HIG "\n你只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！"NOR"\n");
	add_amount(-1);
	return 1;
}

