// 定魂 子母针特殊技

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「定魂」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
			return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "已经神志恍惚，放胆攻击吧.\n");
		
	if( (int)me->query_skill("zimu-zhen", 1) < 30 )
		return notify_fail("你的子母针法不够娴熟，不会使用「定魂」。\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("你的碧云心法不够高。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱。\n");


	msg = HIG "$N双目突然泛过怪异绿光,中指在不易察觉间微微一动,一点银星悄无声息打向$n眉心。\n"NOR;

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += HIR " 结果$p被$P的「定魂」打个正着，瞬间神志开始迷糊起来！\n" NOR;
                target->start_busy( (int)me->query_skill("zimu-zhen") / 20 );
        target->apply_condition("tmzhuihun_poison", 10);

	} else {
		msg += "可是$p在千钧一发之间闪身躲过了这一击。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
