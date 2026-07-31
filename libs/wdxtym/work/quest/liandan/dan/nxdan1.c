//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}


void create()
{
	set_name(RED "续命八丹" NOR, ({"xuming badan", "badan", "dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("value", 10000);
		set("medicine", 1);
	}

	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	if (me->query_condition("insect_poison") > 30)
	me->apply_condition("insect_poison", 0);
	if (me->query_condition("snake_poison") > 30)
	me->apply_condition("snake_poison", 0);
	if (me->query_condition("sl_poison") > 30)
	me->apply_condition("sl_poison", 0);
	if (me->query_condition("xx_poison") > 30)
       	me->apply_condition("xx_poison", me->query_condition("xx_poison") - 30); 
	if (me->query_condition("xx_poison") > 50)
        me->apply_condition("xx_poison", me->query_condition("xx_poison") - 50);
	message_vision(HIG "$N吃下一粒续命八丹，把命吊了回来! \n" NOR, me);

	destruct(this_object());
	return 1;
}
