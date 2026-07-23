// sandu.c 抽髓掌散毒
// By Yzuo 97.04

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("施毒只能对战斗中的对手使用。\n");

	if( !target || !target->is_character() )
		return notify_fail("施毒只能对对手使用。\n");
	if( !(int)me->query_condition("poison_sandu"))
		return notify_fail("你现在没毒可散。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

//	if( !userp(target) || wizardp(target) )
//		return notify_fail("散毒只能对玩家使用。\n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
		return notify_fail("对这人散毒是没用的。\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能散毒。\n");

	if( (int)me->query_skill("chousui-zhang", 1) < 40 )
		return notify_fail("你的抽髓掌不够娴熟，不能散毒。\n");

	msg = GRN "只听得$N的骨节格格作响，$N的手猛地长了半尺，居然一把抓住$n手
腕，将毒质运于手心，源源不断传入$n体内。\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("chousui-zhang",1))
          > random(target->query_skill("dodge") ) ) {
		msg += CYN " 结果$p无力挣扎，$P的本身阴毒不断散入$n体内！\n" NOR;
            target->receive_damage("qi",20);
            target->receive_wound("qi",15 + random(10));
	 target->apply_condition("xx_sandu",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
            target->apply_condition("poison_sandu", 1000);
            me->apply_condition("poison_sandu", 0);
            target->start_busy(1 + random(2));
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	} else {
		msg += "可是$p急提内力奋力一震，将$N的手震了开去。\n" NOR;
		me->start_busy(3);
		message_combatd(msg, me, target);
	}
me->kill_ob(target);
//	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
