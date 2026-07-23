// cuixin.c  九阴神掌「神掌催心」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「神掌催心」只能对战斗中的对手使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「神掌催心」！\n");   

        if(me->query_skill("jiuyin-zhengong",1) < 150 )
                return notify_fail("你的九阴真功不够娴熟，还使不出「神掌催心」。\n");
	if( (int)me->query_skill("jiuyin-shenzhang", 1) < 150 )
		return notify_fail(WHT"你的九阴神掌不够娴熟，还使不出「神掌催心」。\n"NOR);
	if( (int)me->query_skill("force", 1) < 180 )
		return notify_fail(RED"你的内功心法火候不够，使用「神掌催心」会震伤自己的经脉。\n"NOR);
	if( !target->is_busy() )
		return notify_fail(RED"「神掌催心」只能趁忙乱中对对手使用。\n"NOR);
	if( (int)me->query("neili") < 900 )
		return notify_fail("你内力不够了。\n");

	msg = HIB"$N趁着$n手忙脚乱之时，使出“神掌催心”，九阴真气直透$n心脉！\n"NOR;
	me->start_busy(2);
        me->start_perform(3, "神掌催心");
	me->add("neili", -600);
	damage = target->query("eff_qi");
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/2	)
{
		target->receive_damage("qi", damage/5);
		target->receive_wound("qi", damage/5);
		msg += HIR"$n只觉心脉一震，一口鲜血狂喷而出！！！\n"NOR;
	} else if (random(me->query("combat_exp")) > target->query("combat_exp")/3) {
		target->receive_damage("qi", damage/14);
		target->receive_wound("qi", damage/14);
		msg += HIR"$n急提一口真气护住心脉，一拼之下， 口中不由流出一丝鲜血！\n"NOR;
	} else {
		target->add("neili", -600);
		msg += HIY"$N只觉$n内力浑厚，劲力根本无法攻入。\n"NOR;
	}
	message_combatd(msg, me, target);
}
else {
	if (random(me->query("neili")) > target->query("neili")) {
		target->receive_damage("qi", damage/6);
		target->receive_wound("qi", damage/6);
		msg += HIR"$n只觉心脉一震，一口鲜血狂喷而出！！！\n"NOR;
	} else if (me->query("neili") > target->query("neili") / 3) {
		target->receive_damage("qi", damage/14);
		target->receive_wound("qi", damage/14);
		msg += HIR"$n急提一口真气护住心脉，一拼之下， 口中不由流出一丝鲜血！\n"NOR;
	} else {
		target->add("neili", -600);
		msg += HIY"$N只觉$n内力浑厚，劲力根本无法攻入。\n"NOR;
	}
	message_combatd(msg, me, target);
}
	return 1;
}
