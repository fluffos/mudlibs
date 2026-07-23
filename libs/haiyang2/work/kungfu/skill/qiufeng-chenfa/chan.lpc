// chan.c 秋风尘法 缠字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的内力还不够高！\n");

	if( (int)me->query_skill("qiufeng-chenfa", 1) < 60)
		return notify_fail("你秋风尘法的修为不够，不能使用缠字诀! \n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
                        return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

	msg = CYN "$N使出秋风尘法「缠」字诀，拂尘连挥企图把$n的全身缠住。\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "结果$p被$P攻了个措手不及。\n" NOR;
		target->start_busy( (int)me->query_skill("qiufeng-chenfa") / 60 + 2);
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	me->add("neili",-100);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
