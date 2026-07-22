#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "drink");
}

void create()
{
	set_name(HIW "乳酪" NOR, ({ "ru lao", "cheese"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一碗香甜的鲜奶酪，不喝奶酪就不算来过大草原。\n");
		set("unit", "碗");
		set("value",5000);
             }
}

int do_drink(string arg)
{
	object me = this_player();
	object ob = this_object();

	if (!arg || !id(arg))
		return notify_fail("你想喝什么？\n");
	if( me->query("water") < me->max_water_capacity()
	 && me->query("food") < me->max_food_capacity()){
		message_vision(HIG "$N骨碌骨碌地喝完一碗" + ob->name()+ HIG "，抹了抹嘴。\n"NOR,me);
		me->add("food", 100);
		me->add("water", 100);
		destruct(ob);
		return 1;
	}
}
