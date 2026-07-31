//sogu.c   搜骨鹰爪

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if((int)me->query_str() < 30)
                return notify_fail("你臂力不够,不能使用搜骨鹰爪！\n");

        if((int)me->query_skill("shenghuo-xuanming",1) < 100)
                return notify_fail("你圣火玄冥功的功力不够，不能使用搜骨鹰爪！\n");

        if((int)me->query_skill("yingzhua-qinna",1) < 150)
                return notify_fail("你的鹰爪擒拿手修为不够,目前还不能使用搜骨鹰爪！\n");

	if((int)me->query("neili") < 800)
                return notify_fail("你内力现在不够, 不能使用搜骨鹰爪！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

        msg = HIY "$N使出鹰爪擒拿功绝技「搜骨鹰爪」，双爪蓦地抓向$n的全身要穴。\n"NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ) {
		msg += "结果$p被$P攻了个措手不及，立时动弹不得！\n" NOR;
                target->start_busy( (int)me->query_skill("yingzhua-qinna",1) / 20 + 2);
		me->add("neili", -200);
	} else {
		msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
