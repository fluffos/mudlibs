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
	set_name(HIR"大还丹"NOR, ({"dahuan dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","这是一颗少林秘制的大还丹，可以增加1000点最大内力。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+name()+"。\n");

	me->add("max_neili",1000);
	write(YEL"你吃下一颗"+name()+YEL+"，发现自己内力大增！"NOR"\n");

	add_amount(-1);
	return 1;
}