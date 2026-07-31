#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("天仙化人只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你使用的武器不对。\n");
                
        if( (int)me->query_skill("emei-ci", 1) < 150 )
                return notify_fail("你的峨嵋刺不够娴熟，不会使用「天仙化人」。\n");
                                
        if( (int)me->query_skill("linji-zhuang", 1) < 150 )
                return notify_fail("你的临济庄不够高，不能用来反震伤敌。\n");
                        
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用「天仙化人」。\n");
                        
        msg = CYN "$N微微一笑，猛吸一口气,欲使出以气驭刺绝技攻击$n。\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/5 )
        {
                target->start_busy( (int)me->query_skill("emei-ci") / 30 + 1);
                
                damage = (int)me->query_skill("dagger", 1);
                damage = damage +  (int)me->query_skill("linji-zhuang", 1);
                damage = damage +  (int)me->query_skill("emei-ci", 1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage);
                msg += HIR"只见$N手掐法决,峨嵋刺幻作一道金光,腾空而起,倏的罩向$n,\n$n只觉一股大力铺天盖地般压来,登时眼前一花，两耳轰鸣,哇的喷出一口鲜血！！\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
