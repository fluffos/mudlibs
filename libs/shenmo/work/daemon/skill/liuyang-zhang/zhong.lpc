// zhong.c 种生死符

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准打架。\n");

        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「生死符」只能在战斗中使用。\n");

	if( !target || !target->is_character() )
		return notify_fail("生死符只能种在对手身上。\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 40 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 40 ))
		return notify_fail("你的本门内功不够娴熟，不能种生死符。\n");

	if (me->query("neili")<200)
		return notify_fail("你真气不足。\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 40 )
		return notify_fail("你的天山六阳掌不够娴熟，不能种生死符。\n");


	msg = CYN "$N化水为冰，凝于掌中，轻飘飘地拍向$n。\n";

	me->start_busy(1);

 if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
 {
		msg += CYN " 结果$p被$P攻了个正着！\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1));
		target->receive_wound("qi",155 + random( (int)me->query_skill("liuyang-zhang",1)));
		target->receive_wound("jing", 10);
		target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + 30 +
		target->query_condition("ss_poison"));
		me->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(2);
		message_combatd(msg, me, target);
	}
        me->add("neili",-60);
// if target is not busy, then busy him (by xbd)
	if (!target->is_busy()) target->start_busy(1 + random(2));
//	if( !target->is_killing(me) ) target->kill_ob(me);
//	if(!target->is_fighting(me)) target->fight_ob(me);
//	destruct(obj);

	return 1;
}
