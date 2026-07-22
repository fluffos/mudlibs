// qiannianshouwu.c 千年何首乌
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
	set_name(YEL"千年首乌"NOR, ({"qiannian shouwu", "shouwu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵千年首乌，形状宛如人体，传说千年方出一棵。\n");
		set("value", 10000);
	}
	setup();
}

 
int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	if (me->query_condition("medicine")) {
        me->add("max_neili", -20);
		message_vision(
			HIR "$N吃下一株千年首乌，只觉口干舌燥，眼前发黑。\n"
			"原来服食太急太多，药效适得其反！\n" NOR, this_player());
	} else {
	     message_vision(
	   HIG "$N吃下一棵千年首乌，一股热流自丹田涌入七经八络，功力大增!\n" NOR, me);
	me->apply_condition("medicine", 30);
        me->reincarnate();
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jingli", me->query("eff_jingli"));
        me->set("neili", me->query("max_neili"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        me->add("max_neili",10);
      
	}
	destruct(this_object());
	return 1;
}
