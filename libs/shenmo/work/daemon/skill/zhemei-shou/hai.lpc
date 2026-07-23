// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HAI "「" HIC "海渊式" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HAI "只能对战斗中的对手使用。\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail(HAI "只能空手施展。\n");

        if (me->query_skill("force") < 200)
                return notify_fail("你的内功火候不够，难以施展" HAI "。\n");

        if ((int)me->query_skill("zhemei-shou", 1) < 130)
                return notify_fail("你的逍遥折梅手等级不够，难以施展" HAI "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你现在真气不足，难以施展" HAI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIB "$N" HIB "挥手疾舞，施出逍遥折梅手「海渊式」，手法"
              "缥缈，虚虚实实罩向$n" HIB "要害。\n" NOR;

        me->add("neili", -50);
        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("hand") * 3;
                me->add("neili", -100);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "霎时漫天掌影化为一抓，$p" HIR "闪"
                                           "避不及，被$N" HIR "五指插入胸膛，鲜血"
                                           "四处飞溅！\n" NOR;


                me->start_busy(2);
        } else 
        {
                me->add("neili", -50);
                msg += HIC "可是$p" HIC "身手敏捷，身形急转，巧妙的躲过了$P"
                       HIC "的攻击。\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

