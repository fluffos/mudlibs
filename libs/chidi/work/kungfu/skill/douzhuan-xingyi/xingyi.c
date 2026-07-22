// xingyi.c 斗转星移perform星移斗转

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("星移斗转只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("douzhuan-xingyi", 1) < 120 )
		return notify_fail("你的星移斗转还未练成，不能使用！\n");

	if( (int)me->query("neili") < 350 )
		return notify_fail("你现在内力不足，不能使用星移斗转！\n");

	if( (int)me->query_skill("parry", 1) < 120 )
		return notify_fail("你的基本招架之法不够娴熟，不能使用星移斗转。\n");

	msg = HIY "\n忽然天昏地暗，$N使出$n的绝招，袍袖中两股内家真气向$n扑去！\n"NOR;
	if( weapon = target->query_temp("weapon") ){
		if( random(me->query_str()) > (int)target->query_str() / 2 ) {
			msg += HIY"\n$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出，手中"
			+ target->query_temp("weapon")->query("name") + "坠地而出。\n" NOR;
			message_vision(msg, me, target);
			(target->query_temp("weapon"))->move(environment(target));
		}
		else {
			msg += HIY"\n$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的\n躲过这一招，脸色变的苍白。\n" NOR;
			message_vision(msg, me, target);
		}
		me->start_busy(3);
	}
	else
	{
		if (random(me->query_skill("parry")) > target->query_skill("parry") / 2 )
		{
			me->start_busy(3);
//			target->start_busy(random(3));
			damage = (int)me->query_skill("shenyuan-gong", 1);
			damage = damage*3 + random(damage);
			target->receive_damage("qi", damage);
			target->receive_wound("qi", damage);

			if( damage < 300 ) msg += HIY"\n结果$n脸色变得惨白，踉踉跄跄退了好几步！\n"NOR;
			else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
			else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
			else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;

		}
		else
		{
			me->start_busy(3);
			msg += HIY"\n$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的\n躲过这一招，脸色变的苍白。\n" NOR;
		}
		message_vision(msg, me, target);

	}
	me->add("neili", -150);
	return 1;
}
