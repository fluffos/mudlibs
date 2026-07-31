// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jie.c 华山剑法「截手式」

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

#define JIE "「" HIG "截手式" NOR "」"

int perform(object me, object target)
{
        object weapon;
        int level, ap, dp;
        string msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/huashan-jianfa/jie"))
                return notify_fail("你还没有受过高人指点，无法施展" JIE "。\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIE "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
                
        if ((level = me->query_skill("huashan-jianfa", 1)) < 30)
                return notify_fail("你的华山剑法不够娴熟，无法施展" JIE " 。\n");

        if (me->query_skill_mapped("sword") != "huashan-jianfa")
                return notify_fail("你没有激发华山剑法，无法施展" JIE "。\n");

        if (me->query("neili") < 60)
                return notify_fail("你现在真气不够，无法使用「截手式」。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "\n但见$N" HIW "长剑一勒，使出华山剑法绝技之"
              "「" HIG "截手式" HIW "」，转折之际天衣无缝，一"
              "剑既出，后着源源倾泻，如大浪跃滩，层层叠叠，迅"
              "然扑向$n" HIW "！\n" NOR;

        me->add("neili", -50);
        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp) 
        {
                msg += HIR "结果$p" HIR "瘁不及防，连连倒退"
                       "几步，一时间无法回手！\n" NOR;
                target->start_busy(level / 80 + 3);
//                target->start_busy(level / 30 + 2);^M
        } else
        {
                if (objectp(weapon = target->query_temp("weapon")))
                        msg += CYN "但是$p" CYN "识破了$P" CYN "的用意，"
                               "自顾将手中的" + weapon->name() +
                               CYN "舞成一团光花，$P"
                               CYN "一怔之下再也攻不进去。\n" NOR;
                else
                        msg += CYN "但是$p" CYN "双手戳点刺拍，将$P"
                               CYN "的来招一一架开。\n" NOR;

                me->start_busy(1);
        }
        message_sort(msg, me, target);

        return 1;
}

