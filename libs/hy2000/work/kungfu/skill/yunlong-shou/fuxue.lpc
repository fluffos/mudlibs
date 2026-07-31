// fuxue.c 拈花指 「拈花拂穴」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("拂穴只能对战斗中的对手使用。\n");

	if((int)me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");

	if((int)me->query_skill("yunlong-shou",1) < 100)
		return notify_fail("你云龙手的功力不够不能使用拂穴!\n");

	if((int)me->query_skill("hand") < 100)
		return notify_fail("你的手法修为不够,目前还不能使用拂穴绝技!\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够, 不能使用拂穴! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = HIY "$N使出云龙手绝技「拂穴」，罩住了$n的全身要穴, 使$n动弹不得。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 )
	{
		msg +=  HIG "结果$p被$P攻了个措手不及! \n" NOR;
		target->start_busy( (int)me->query_skill("yunlong-shou",1) / 50 + 2);
		me->add("neili", -100);
	}
	else
	{
		msg += HIM "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
