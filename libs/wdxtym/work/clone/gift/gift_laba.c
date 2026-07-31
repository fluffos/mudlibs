
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
	set_name(MAG"腊八粥"NOR, ({"laba zhou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一碗侠客岛熬制的腊八粥，据说可以增加人物的内力值！\n");
		set("unit", "碗");
		set("base_unit", "碗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int num1,num2,num3,num4;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	num1=50+random(50);
	me->add("max_neili",num1);

	message_vision("$N喝下一" + query("unit") + name() + "。\n", me);
	write(YEL"恭喜您：增加了"+num1+"点内力。"NOR"\n");
	add_amount(-1);
	me->save();
	return 1;

}
