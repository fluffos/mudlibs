// ju.c 昊天掌-三花聚顶
// By Lgg,1998.10

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("三花聚顶只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("haotian-zhang", 1) < 50 )
                return notify_fail("你的昊天掌不够娴熟，不会使用三花聚顶。\n");

        if( (int)me->query_skill("xiantian-qigong", 1) < 50 )
                return notify_fail("你的先天功不够娴熟，不会使用三花聚顶。\n");

        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("你现在内力太弱，不能使用三花聚顶。\n");

        msg = HIC "$N大喝一声，合身向$n扑上，双掌同时击出，是一招「三花聚顶」。\n"NOR;

//        if( !target->is_killing(me) ) target->kill_ob(me);
        if( !target->is_fighting(me) ) me->fight_ob(target);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(1);

                damage = (int)me->query_skill("haotian-zhang", 1) + (int)me->query_skill("force",1);
                //(昊天掌级别+基本内功)

                damage = damage/2 + random(damage/2) ;

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                target->start_busy(6);
                me->add("neili", -100);

                msg += HIR"结果$n被$N的气势所摄，一惊之下，竟然忘了抵挡！\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
                me->start_busy(2);
                me->add("neili", -100);
                msg += CYN"可是$p识破了$P这一招，斜斜一跃避开。\n"NOR;
		message_combatd(msg, me, target);
        }

        return 1;
}
