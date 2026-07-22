// guazi.c

inherit ITEM;
#include <ansi.h>;

void create()
{
	set_name( "北京烤鸭" , ({ "kaoya","duke" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只烤得焦黄的鸭子。\n");
		set("unit", "只");
		set("value", 50000);
		set("remaining", 1);
		set("food_supply", 15);
	}
	setup();
}
void init()
{
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if( !this_object()->id(arg) ) return 0;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if(   (int)me->query("food") >= (int)me->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也吃不下了。\n");
	message_vision("$N吃下一只北京烤鸭。\n",me);
	me->add("food", (int)query("food_supply"));
	if( me->is_fighting() ) me->start_busy(2);
	destruct(ob);
	return 1;
}

   
