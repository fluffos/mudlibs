// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YING "「" HIR "无影神拳" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl;

        if (! target) target = offensive_target(me);



        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "只能对战斗中的对手使用。\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("你必须空手才能施展" YING "。\n");

        if (me->query_skill_mapped("unarmed") != "shenzhao-jing")
                return notify_fail("你没有激发神照经神功为空手技能，无法施展" YING "。\n");



        if ((int)me->query_skill("shenzhao-jing", 1) < 200)
                return notify_fail("你的神照经神功火候不够，无法施展" YING "。\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("你的基本拳脚火候不够，无法施展" YING "。\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("你的内力修为不足，无法施展" YING "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法施展" YING "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "倏然跃近，无声无影击出一拳，去势快极，拳影重"
              "重叠叠，直袭$n" HIR "而去。\n"NOR;

        lvl = me->query_skill("shenzhao-jing", 1);

        ap = me->query_skill("force")  + me->query("con") * 10;
        dp = target->query_skill("force")   + target->query("con") * 10; 

        me->start_busy(4);
        if (ap * 11 / 20 + random(ap) > dp)
        { 
                damage = me->query_skill("force");
                me->add("neili", -400);
                target->apply_condition("shenzhao",lvl/2);
       target->add("qi",-damage+500);
		target->add("eff_qi",-damage+500);
                msg += HIR "$n" HIR "见拳势变换莫测，只是"
                               "微微一愣，已被$N" HIR "一拳正中胸口，神照经内"
                               "劲顿\n时便如山洪爆发一般，透体而入。\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "见$N" CYN "来势汹涌，急忙提气跃开。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

