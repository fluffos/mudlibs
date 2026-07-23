// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// qian.c

#include <ansi.h>
#include <combat.h>

#define QIAN "「" HIR "乾坤无量" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" QIAN "。\n");

        if (me->query_skill("force") < 150)
                return notify_fail("你的内功的修为不够，难以施展" QIAN "。\n");

        if (me->query_skill("wuliang-jian", 1) < 100)
                return notify_fail("你的无量剑法修为不够，难以施展" QIAN "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你的真气不够，难以施展" QIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "只见$N" HIR "手中" + weapon->name() + HIR "“唰"
              "唰唰唰”连攻四剑，剑招去势极快，全然笼罩$n" HIR "！\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");
                me->add("neili", -150);
                me->start_busy(2);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "结果$n" HIR "阻挡不及，顿时被$N"
                                           HIR "斩中数剑，伤口见骨，苦不堪言。\n"
                                           NOR;
        } else
        {
                me->add("neili", -50);
                me->start_busy(3);
                msg += CYN "可却见" CYN "$n" CYN "猛的拔地而起，避开了"
                       CYN "$N" CYN "的剑招。\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

