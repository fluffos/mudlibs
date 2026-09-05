// qisuck.c

#include <ansi.h>


int exert(object me, object target)
{
	int sp, dp;


	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的真气？\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过真气！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人真气！\n");

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("你必须在战斗中才能吸取对方的真气！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 30 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的真气。\n");

	if( (int)me->query("neili",1) < 10 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经真气涣散，你已经无法从他体内吸取真气了！\n");

	message_vision(
		HIR "$N突然诡异的一笑，双手一扬，拇指对准$n的掌心按了过来！\n\n" NOR,
		me, target );

	if( !target->is_killing(me->query("id")) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

	me->set_temp("sucked", 1);		
//命中率级别C-
	if( F_KUNGFU->hit_rate(sp, dp, 9, me, target) )
	{
		tell_object(target, HIR "你突然觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的真气自手掌源源不绝地流了进来。\n" NOR);

		target->receive_damage("qi", (int)me->query_skill("huagong-dafa", 1), me);
		me->add("qi", (int)me->query_skill("huagong-dafa", 1) );

		if( target->query("combat_exp") >= me->query("combat_exp") )
		{
			me->add("combat_exp",1);
			me->add("exp/suck",1); //增加suck的经验记录，跟踪是否利用此bug
		}

		me->start_busy(random(2));
		target->start_busy(random(2));
		me->add("neili", -5);
        COMBAT_D->report_status(target);
		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
		me->start_busy(2);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
//        if( !me ) me = this_player(1);
        if( !me ) return;
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
