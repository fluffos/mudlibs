// mie.c  回风拂柳剑法「灭剑」

#include <ansi.h>
#include <combat.h>

//inherit F_CLEAN_UP;

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
//        if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "sword")
//                return notify_fail(RED"开什么玩笑，没装备剑就想使「迷踪幻影连环脚」？\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「迷踪幻影连环脚」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("shadowsteps", 1) < 80)
                return notify_fail(WHT"你的迷踪幻影步不够娴熟，还使不出「迷踪幻影连环脚」。\n"NOR);

        if ( me->query_temp("weapon"))
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);

        if ((int)me->query("neili")<200)
        {
               return notify_fail(HIC"你现在内力不够，没能将「迷踪幻影连环脚」使完！\n"NOR);
        }
	msg = HIC  "$N施展出［迷踪幻影连环脚］，身形极度旋转，一丛人影中突然向$n飞出一腿！\n" NOR;
                me->start_busy(2);
                if (!target->is_busy())
                target->start_busy(random(2));
                damage = (int)me->query_skill("shadowsteps", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                me->add("neili", -50);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
         msg = HIC  "人影中又飞出一腿！\n" NOR;
                 me->start_busy(2);
                if (!target->is_busy())
                target->start_busy(random(2));
                damage = (int)me->query_skill("shadowsteps", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                me->add("neili", -50);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        msg = HIC  "$N身形渐稳，反身又是一腿！\n" NOR;
                  me->start_busy(2);
                target->start_busy(random(2));
                damage = (int)me->query_skill("shadowsteps", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                me->add("neili", -50);
                  message_vision(msg, me, target);
		COMBAT_D->report_status(target);
    return 1;
}


