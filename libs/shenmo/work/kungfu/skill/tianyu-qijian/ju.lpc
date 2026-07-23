// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JU "「" HIR "聚剑诀" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage, ap, dp;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JU "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" JU "。\n");

        if ((int)me->query_skill("tianyu-qijian") < 130)
                return notify_fail("你的天羽奇剑不够娴熟，难以施展" JU "。\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("你的内功火候不足，难以施展" JU "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在的真气不足，难以施展" JU "。\n");
                        
        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        ap = me->query_skill("sword");
        dp = target->query_skill("force");
             
        msg = HIR "$N" HIR "手腕轻轻一抖，手中的" + weapon->name() +
              HIR "化作一道彩虹，光华眩目，笼罩了$n" HIR "。\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");

                me->add("neili", -160);
  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "只见$N" HIR "剑花聚为一线，穿向$n"
                                           HIR "，$p" HIR "只觉一股热流穿心而过，"
                                           "喉头一甜，鲜血狂喷而出！\n" NOR;

                me->start_busy(2);
        } else 
        {
                msg += CYN "可是$p" CYN "猛地向前一跃,跳出了$P"
                       CYN "的攻击范围。\n"NOR;
                me->add("neili", -80);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

