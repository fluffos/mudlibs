// by darken@SJ
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name(){ return HBBLU"轰雷双掌"NOR; }
int perform(object me, object target)
{
        int p, j, ap, dp;
        string msg;

        j = me->query_skill("tiezhang-zhangfa", 1);

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
          || !me->is_fighting(target)
          || !living(target)
          || environment(target)!= environment(me))
                return notify_fail("「轰雷双掌」只能在战斗中对对手使用。\n");

        if( objectp(me->query_temp("weapon")) && !me->query_temp("tzzf") )
                return notify_fail("你必须空手才能使用「轰雷双掌」！\n");

        if( (int)me->query_skill("tiezhang-zhangfa", 1) < 220 )
                return notify_fail("你的铁掌不够娴熟，使不出「轰雷双掌」绝技。\n");

        if( (int)me->query_skill("guiyuan-tunafa", 1) < 220 )
                return notify_fail("你归元吐纳法不够，使不出轰雷双掌绝技。\n");

        if( (int)me->query("jiali") < 120 )
                return notify_fail("你加力不够，使不出「轰雷双掌」绝技。\n");

        if (me->query_skill_mapped("force") != "guiyuan-tunafa")
                return notify_fail("你所使用的内功不对。\n");

        if( (int)me->query_skill("force") < 320 )
                return notify_fail("你的内功等级不够，不能使用「轰雷双掌」。\n");

        if( (int)me->query_str(1) < 50 )
                return notify_fail("你的膂力还不够强劲，使不出「轰雷双掌」来。\n");

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
         || me->query_skill_mapped("strike") != "tiezhang-zhangfa"
         || me->query_skill_mapped("parry") != "tiezhang-zhangfa")
                return notify_fail("你现在无法使用「轰雷双掌」！\n");

        if( (int)me->query("max_neili") < 4000)
                return notify_fail("你现在内力太弱，使不出「轰雷双掌」。\n");

        if( (int)me->query("neili") < 3000 )
                return notify_fail("你现在真气太弱，使不出「轰雷双掌」。\n");

	msg = HBBLU "\n$N蓦地里转身，使出铁掌掌法中的“轰雷双掌”对$n胸口双掌推出！\n"NOR;
	

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if ( me->query_skill("tiezhang-zhangfa", 1) > 350 )
		ap += random(ap/3);

	if ( target->is_busy())
		dp -= dp/3;

	if (random( ap + dp) > dp ) {
		msg += HIR"结果一击命中，$n向后飞出足足三四丈远，口中鲜血狂喷！\n"NOR;
		j *= 5;
		j += me->query("jiali") * 5;
		j *= 2;
		j += random(j/2);
		j -= target->query_con(1)* 20;

		j = j/2 + random(j/2);

		tell_object(me, sprintf("damage: %d", j));

		if ( j > 6000 )
			j = 6000 + (j - 6000)/10;

		target->receive_damage("qi", j, me);
		target->receive_wound("qi",j/3+random(j/3), me);
		me->add("neili", -400);
		me->add("jingli", -150);
		me->start_perform(3, "「轰雷双掌」");
		if (random(2)) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(j, "震伤");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(j, "震伤");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
	}
	else {
		msg += CYN"$n见来势猛恶，急忙远远避开。\n"NOR;
		me->add("neili", -100);
		me->add("jingli", -80);
		me->start_perform(2, "「轰雷双掌」");
	}
	me->start_busy(random(2));
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
        write(HBBLU"\n铁掌掌法之「轰雷双掌」："NOR"\n\n");
        write(@HELP
        要求：  内力 3000 以上；
                最大内力 4000 以上；
                后天膂力 50 以上；
                铁掌掌法等级 220 以上；
                归元吐纳法等级 220 以上；
                有效内功等级 320 以上；
                加力 120 以上；
                激发内功为归元吐纳法；
                激发掌法为铁掌掌法；
                激发招架为铁掌掌法；
                且手无兵器。

HELP
        );
        return 1;
}
