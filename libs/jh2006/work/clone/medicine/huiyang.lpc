#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("回阳五龙膏", ({"wulong gao", "huiyang", "wulong", "gao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("heal_up", 1);
		set("long","这是一包由草乌制成的崆峒派伤药。\n");
		set("value", 3000);
		set("base_value", 3000);
		set("base_unit", "份");
		set("base_weight", 500);
	}
	set_amount(1);
}

void init()
{
	add_action("do_eat", "fu");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要吃什么？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (me->query("eff_qi") >= me->query("max_qi"))
		return notify_fail("你现在不需要服回阳五龙膏。\n");
	me->receive_curing("qi", 100+random(100));
	message_vision("$N服下一份回阳五龙膏，脸色看起来好多了。\n", me);
	me->start_busy(1);
	add_amount(-1);
	return 1;
}
