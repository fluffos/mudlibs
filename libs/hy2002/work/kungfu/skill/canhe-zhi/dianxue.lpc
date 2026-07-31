// fuxue.c 拈花指 「拈花点穴」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「拈花点穴」只能在战斗中使用。\n");

	if((int)me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");

	if((int)me->query_skill("canhe-zhi",1) < 150)
		return notify_fail("你参合指的功力不够不能使用拈花点穴!\n");

	if((int)me->query_skill("finger") < 100)
		return notify_fail("你的指法修为不够,目前还不能使用拈花点穴绝技!\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够, 不能使用拈花点穴! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = HIG "$N使出参合指绝技「拈花点穴」，一指向$n的全身要穴点去, 使$n动弹不得。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3 )
	{
		msg +=  HIG "结果$p被$P点中了几个穴位! \n" NOR;
		target->start_busy( (int)me->query_skill("canhe-zhi",1) / 50 + 2);
		me->add("neili", -100);
	}
	else
	{
		msg += HIM "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
