// throw.c 灵蛇杖法喷毒
// By Yzuo 97.04

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( !target || !target->is_character() )
		return notify_fail("喷毒只能对对手使用。\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");
	if( (int)me->query_skill("hamagong", 1) < 40 )
		return notify_fail("你的蛤蟆功不够娴熟，不能喷毒。\n");

	if( (int)me->query_skill("lingshe-zhangfa", 1) < 40 )
		return notify_fail("你的灵蛇杖法不够娴熟，不能喷毒。\n");

	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("你的内力不够，不能喷毒。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");

	if( (string)weapon->query("id") != "she zhang" )
		return notify_fail("你手中没有蛇杖，不能喷毒。\n");

        me->add("neili", -200);

	msg = MAG "$N喉间发出刺耳的格格声响，蛇杖前头的小蛇猛地扬头，一阵粉红毒雾带着甜香喷向$n。\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("lingshe-zhangfa",1))
          > random(target->query_skill("dodge")) )
        {
		msg += MAG "结果$p被$P杖头小蛇一口喷中！\n" NOR;
		if (target->query("neili") < me->query("neili"))
		{
	msg += MAG "$p只闻到一阵甜香，眼前就模糊起来。\n" NOR;
	target->receive_damage("qi",(int)me->query_skill("lingshe-zhangfa",1));
	target->receive_wound("qi",15 + random(10));
	target->receive_wound("jing", 10);
	target->apply_condition("qx_snake_poison",20);
	target->apply_condition("snake_poison",10);
	target->apply_condition("chanchu_poison",10);
	target->apply_condition("snake_poison", random(me->query_skill("lingshe-zhangfa",1)/10) + 1 +
		target->query_condition("snake_poison"));
	target->start_busy(1 + random(2));
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
		}
		else
		{
	msg += CYN "$p急运内力，一口真气向蛇毒喷去，顿时蛇毒反向$P飘了回去。\n" NOR;
	msg += MAG "$P只闻到一阵甜香，眼前就模糊起来。\n" NOR;
	me->receive_damage("qi",(int)me->query_skill("lingshe-zhangfa",1));
	me->receive_wound("qi",15 + random(10));
	me->receive_wound("jing", 10);
	me->apply_condition("snake_poison", random(me->query_skill("lingshe-zhangfa",1)/10) + 1 +
		me->query_condition("snake_poison"));
	me->start_busy(1 + random(2));
	message_combatd(msg, me, target);
	COMBAT_D->report_status(me);
		}
	} else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
		message_combatd(msg, me, target);
	}
me->kill_ob(target);
//	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
