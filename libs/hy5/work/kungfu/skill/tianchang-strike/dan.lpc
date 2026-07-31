#include <ansi.h>
#include <combat.h>

#define DAN "「" HIM "丹阳劲" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DAN "只能对战斗中的对手使用。\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("你必须空手才能使用" DAN "。\n");         
                
        if ((int)me->query_skill("tianchang-strike", 1) < 40)
                return notify_fail("你的掌法不够娴熟，难以施展" DAN "。\n");

        if (me->query("max_neili") < 200)
                return notify_fail("你的内功修为不足，难以施展" DAN "。\n");

        if (me->query_skill_mapped("strike") != "tianchang-strike")
                return notify_fail("你没有激发天偿掌法，难以施展" DAN "。\n");

        if (me->query_skill_prepared("strike") != "tianchang-strike")
                return notify_fail("你没有准备天偿掌法，难以施展" DAN "。\n");

        if (me->query("neili") < 50)
                return notify_fail("你现在真气太弱，难以施展" DAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIM "$N" HIM "凝聚内力，深深吸入一口气，掌劲吞吐，对准$n"
              HIM "平平拍出。\n" NOR;
        me->add("neili", -30);

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                me->start_busy(3);
                target->start_busy(random(3));
                
                damage = (int)me->query_skill("force", 1);
                damage = damage / 2 + random(damage)+120;
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "见势连忙向后一纵，但却只觉"
                                           "胸口一震，顿时两耳轰鸣，已被$N" HIR "掌"
                                           "劲所伤！\n" NOR;                

        } else 
        {
                me->start_busy(3);
                msg += CYN "可是$p" CYN "看破了$P"
                       CYN "的企图，并没有上当。\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}

