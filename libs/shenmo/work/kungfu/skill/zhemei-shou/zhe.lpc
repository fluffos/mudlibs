// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHE "「" HIC "折梅式" NOR "」"

inherit F_SSERVER;

 
int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int skill, ap, dp;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHE "只能对战斗中的对手使用。\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail(ZHE "只能空手施展。\n");

        skill = me->query_skill("zhemei-shou", 1);

        if (skill < 80)
                return notify_fail("你的折梅手等级不够，难以施展" ZHE "。\n");

        if (me->query_skill("force") < 120)
                return notify_fail("你内功火候不够，难以施展" ZHE "。\n");

        if (me->query("neili") < 200)
                return notify_fail("你现在真气不足，难以施展" ZHE "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIC "$N" HIC "合逍遥折梅手诸多变化为一式，随手轻轻挥出，虚虚"
              "实实笼罩$n" HIC "全身诸处要穴。\n" NOR;
 
        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        
        me->add("neili", -80);
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -50);
                msg += HIR "$n" HIR "心头一颤，想不出破解之法，急忙后"
                      "退数步，一时间无法反击。\n" NOR;
                target->start_busy(ap / 100 + 2);
        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN "的企图，丝"
                      "毫不为所动，让$P" CYN "的虚招没有起得任何作用。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

