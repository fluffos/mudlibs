//Cracked by Roath
// Modified by iszt@pkuxkx, 2007-03-30, added faint_me

#include <ansi.h>

int valid_leave(object me, string dir)
{
	int food = me->max_food_capacity();
	int water = me->max_water_capacity();
	object camel;
	if( userp(me) && ::valid_leave(me, dir)
		&& (!objectp(camel = me -> query_temp("riding"))
		|| camel->name() != HIW"白骆驼"NOR ) )
	{
//		me->add("food", - food / 10);
		me->add("water", - water / 3);
		me->start_busy(2);
		tell_object(me, HIR"你觉得口干舌燥，真是生不如死！\n不知道何时才能走出茫茫大漠。\n"NOR);
		if(me->query("food") < 0 || me->query("water") < 0 )
		{
			remove_call_out("faint_me");
			call_out("faint_me", 1, me);
			me->set("water",0);
		}
	}
	return ::valid_leave(me, dir);
}

int faint_me(object me)
{
	if(random(4))
	{
		message_vision(HIY"$N干渴过度，只觉脑中嗡嗡作响，眼冒金星！\n"NOR, me);
		me->receive_wound("jing", 40, "在沙漠中干渴");
		return 1;
	}
	message_vision(HIY"$N干渴过度，终于体力不支，晕倒在地！\n"NOR, me);
        me->start_busy(300);;
	me->unconcious();
	return 1;
}
