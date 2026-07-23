// cuixin.c  催心掌「催心」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「催心」只能对战斗中的对手使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「催心」！\n");   

	if( (int)me->query_skill("cuixin-zhang", 1) < 150 )
		return notify_fail(WHT"你的催心掌不够娴熟，还使不出「催心」。\n"NOR);
	if( (int)me->query_skill("force", 1) < 180 )
		return notify_fail(RED"你的内功心法火候不够，使用「催心」会震伤自己的经脉。\n"NOR);
	if( !target->is_busy() )
		return notify_fail(RED"「催心」只能趁忙乱中对对手使用。\n"NOR);
	if( (int)me->query("neili") < 800 )
		return notify_fail("你内力不够了。\n");

	msg = HIC "$N阴阴一笑，趁着$n忙乱中递出一掌。\n"NOR;
	msg += HIB "$N的掌势虽轻，但一股阴深的内力却直透$n心脉。\n"NOR;
	me->start_busy(3);
        me->start_perform(3, "催心");
	me->add("neili", -600);
	damage = target->query("qi");
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/2	)
{
		target->receive_damage("qi", damage/6);
		target->receive_wound("qi", damage/10);
		msg += HIR"$n只觉心脉一震，一口鲜血狂喷而出！！！\n"NOR;
	} else if (random(me->query("combat_exp")) > target->query("combat_exp")/3) {
		target->receive_damage("qi", damage/10);
		target->receive_wound("qi", damage/20);
		msg += HIR"$n急提一口真气护住心脉，一拼之下， 口中不由流出一丝鲜血！\n"NOR;
	} else {
		target->add("neili", -600);
		msg += HIY"$N只觉$n内力浑厚，劲力根本无法攻入。\n"NOR;
	}
	message_combatd(msg, me, target);
}
else {	
	if (random(me->query("neili")) > target->query("neili")) {
		target->receive_damage("qi", damage/5);
		target->receive_wound("qi", damage/7);
		msg += HIR"$n只觉心脉一震，一口鲜血狂喷而出！！！\n"NOR;
	} else if (me->query("neili") > target->query("neili") / 2) {
		target->receive_damage("qi", damage/12);
		target->receive_wound("qi", damage/12);
		msg += HIR"$n急提一口真气护住心脉，一拼之下， 口中不由流出一丝鲜血！\n"NOR;
	} else {
		target->add("neili", -600);
		msg += HIY"$N只觉$n内力浑厚，劲力根本无法攻入。\n"NOR;
	}
	message_combatd(msg, me, target);
	return 1;
}
}
