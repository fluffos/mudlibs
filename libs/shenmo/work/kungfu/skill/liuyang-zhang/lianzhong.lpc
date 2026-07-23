// zhong.c 种生死符

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;
	 int extra;
        extra = me->query_skill("liuyang-zhang",1);
	if( !target ) target = offensive_target(me);

        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「连种生死符」只能在战斗中使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准打架。\n");

	if( !target || !target->is_character() )
		return notify_fail("连种生死符只能种在对手身上。\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 200 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 200 ))
		return notify_fail("你的本门内功不够娴熟，不能连种生死符。\n");

	if (me->query("neili")<200)
		return notify_fail("你真气不足。\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
		return notify_fail("你的天山六阳掌不够娴熟，不能连种生死符。\n");


        me->add_temp("apply/strength", extra/4);
        me->add_temp("apply/attack", 80);
	me->add_temp("apply/damage", 380);
	msg = BLU "$N化水为冰，凝于掌中，双指一弹，手上几道青光急速射向$n。\n";
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW  "$N左指一弹，"HIG"第一道生死符"HIW"向$n左边打来！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N右指一弹，"HIG"第二道生死符"HIB"向$n右边打来! " NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "$N凌空跃起,"HIG"第三道生死符"CYN"向$n上面打来!" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/strength", -extra/4);
        me->add_temp("apply/damage", -380);
        me->add_temp("apply/attack", -80);

	me->start_busy(2);
	
 if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
 {
		msg = HIG " 结果$p被$P攻了个正着！身上中了几道生死符\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1));
		target->receive_wound("qi",155 + random( (int)me->query_skill("liuyang-zhang",1)));
		target->receive_wound("jing", 10 + random(50));
		target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/50) + 30 +
		target->query_condition("ss_poison"));
		me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(2);
		message_combatd(msg, me, target);
	}
        me->add("neili",-200);
// if target is not busy, then busy him (by xbd)
	if (!target->is_busy()) target->start_busy(2);
//	if( !target->is_killing(me) ) target->kill_ob(me);
//	if(!target->is_fighting(me)) target->kill_ob(me);

	return 1;
}
