// hunger.c

#include <condition.h>
#include <ansi.h>

int dispel() { return 0; }

int update_condition(object me, int duration)
{
	object *inv;
	int i;
	if (me->query("food") > 0 && me->query("water") > 0)
		return 0;

	if (me->query("zjvip/times") > 0)
		{
			tell_object(me, HIY "你饿得肚子咕咕直叫，幸好地狱使者给你送来了面包和牛奶，你狠狠地吃了几口, 觉得好过了一点 ..."NOR"\n");
			me->set("food", me->max_food_capacity());
			me->set("water", me->max_food_capacity());
			return 0;
		}

	if (! interactive(me) || ! environment(me) || environment(me)->is_chat_room())
		return CND_CONTINUE;

	if (duration == 4)
	{
		if (me->query("food") <= 0 && me->query("water") <= 0)
		{
			tell_object(me, HIY "你饿得头晕眼花，渴得喉咙冒烟，赶紧找点吃的吧。"NOR"\n");
		}
		else if (me->query("food") <= 0)
		{
			tell_object(me, HIY "你饿得头晕眼花，看来要赶快找点吃的了。"NOR"\n");
		}
		else if (me->query("water") <= 0)
		{
			tell_object(me, HIY "你渴得喉咙冒烟，看来要赶快喝点什么了。"NOR"\n");
		}
	}
	else
	if (duration == 7)
	{
		if (me->query("food") <= 0 && me->query("water") <= 0)
			tell_object(me, HIR "你又饥又渴，觉得自己快要死了。"NOR"\n");
		else
		if (me->query("food") <= 0)
			tell_object(me, HIR "你饿得快死了。"NOR"\n");
		else
		if (me->query("water") <= 0)
			tell_object(me, HIR "你渴得要虚脱了。"NOR"\n");
	}
	else
	if (duration >= 13)
	{
		if (me->query("age") < 18)
		{
			tell_object(me, HIY "你眼看就要不行了，突然天上掉下一只烤鸭和一袋米酒，你一阵狂吃滥喝，感觉总算是好多了。"NOR"\n");
			me->set("food", me->max_food_capacity());
			me->set("water", me->max_food_capacity());
			return 0;
		}

		if (me->query("food") <= 0 && me->query("water") == 0)
			tell_object(me, HIR "你又饥又渴，随时都可能晕倒过去。"NOR"\n");
		else
		if (me->query("food") <= 0)
			tell_object(me, HIR "你饿得随时都可能晕倒过去。"NOR"\n");
		else
		if (me->query("water") <= 0)
			tell_object(me, HIR "你渴得随时都可能晕倒过去。"NOR"\n");
		if(me->query("qi")>5)
			me->receive_damage("qi", 5);
		if(me->query("eff_qi")>5)
			me->receive_wound("qi", 5);
		return 0;
	}

	if (duration >= 2)
	{
		inv = all_inventory(me);
		for(i=0;i<sizeof(inv);i++)
		{
			if(!inv[i]->is_cutable()&&me->query("food")<=0&&inv[i]->query("food_remaining"))
			{
				"/cmds/std/eat"->main(me,inv[i]->query("id"));
				break;
			}
			if(me->query("water")<=0&&inv[i]->query("liquid/remaining")>0)
			{
				"/cmds/std/drink"->main(me,inv[i]->query("id"));
				break;
			}
		}
	}

	me->apply_condition("hunger", duration + 1);
	return CND_CONTINUE;
}
