// zhui.c  追命

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「追命」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if( (int)me->query_skill("jinshe-jianfa", 1) < 150 )
                return notify_fail("你的金蛇剑法不够娴熟，不会使用。\n");
                                
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能使用「追命」。\n");
                        
        msg = HIY "$N微微一笑，剑意若有若无，$n却感到莫大的压力。\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                target->start_busy( (int)me->query_skill("jinshe-jianfa") / 20 + 1);
                
                damage = (int)me->query_skill("bahuang-gong", 1);
                damage = damage +  (int)me->query_skill("jinshe-jianfa", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                
                target->receive_damage("qi", damage/3);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage);
                msg += HIR"只见$N剑走了个怪异的弧线，从不可思议的角度向$n杀去,\n$n只觉得背心一阵冰凉，呆呆地看着前胸的剑尖！\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
                me->add("neili", -400);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
