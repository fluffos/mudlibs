// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define SUO "「" CYN "雪锁千山" NOR "」"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int ap, dp, damage;
        string msg, pmsg;
        string *limbs, limb;

        if (userp(me) && ! me->query("can_perform/shentuo-zhang/suo"))
                return notify_fail("你还没有受过高人指点，无法施展" SUO "。\n");  

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(SUO "只能空手施展。\n");

        if ((int)me->query_skill("shentuo-zhang", 1) < 150)
                return notify_fail("你神驼雪山掌火候不够，难以施展" SUO "。\n");

        if (me->query_skill_mapped("strike") != "shentuo-zhang")
                return notify_fail("你没有激发神驼雪山掌，难以施展" SUO "。\n");

        if (me->query_skill_prepared("strike") != "shentuo-zhang")
                return notify_fail("你没有准备神驼雪山掌，难以施展" SUO "。\n");

        if ((int)me->query("neili", 1) < 200)
                return notify_fail("你现在的真气不足，难以施展" SUO "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "一声冷笑，掌势一缓，一招「雪锁千山」，掌上阴劲如怒"
              "涛汹涌，缓缓推向$n。\n" NOR;
        me->add("neili", -20);

        ap = ap_power(me, "strike");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "strike");
                
                pmsg = HIR "霎时只听「喀嚓」一声脆响，$n" HIR "的"
                        "胸口肋骨竟然断了几根。\n" NOR;

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 75, pmsg);
                                                   
                me->start_busy(1);
                me->add("neili", -50);
        } else 
        {
                msg += CYN "可是$n" CYN "看破了$P"
                       CYN "的企图，身形急动，躲开了这一掌。\n"NOR;
                me->start_busy(3);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);

        return 1;
}

