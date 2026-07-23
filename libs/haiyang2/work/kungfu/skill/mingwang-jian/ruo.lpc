// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define RUO "「" HIW "若悲" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(RUO "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" RUO "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((int)me->query_skill("mingwang-jian", 1) < 100)
                return notify_fail("你不动明王剑不够娴熟，难以施展" RUO "。\n");

        if (me->query_skill_mapped("sword") != "mingwang-jian")
                return notify_fail("你没有激发不动明王剑，难以施展" RUO "。\n");

        if (me->query("neili") < 100)
                return notify_fail("你现在的真气不足，难以施展" RUO "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "手中的" + weapon->name() + HIW "轻轻递出，"
              "发出一阵轻鸣，$n" + HIW "听了心中不禁有些迷茫。\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "心头一震，一时竟然沉迷当中，忘记了"
                       "继续攻击。\n" NOR;
                target->start_busy((int)me->query_skill("sword") / 80 + 2);
        } else
        {
                msg += HIC "可是$n" HIC "神智只是略微一滞，随即清醒，没"
                       "有被$P" HIC "所困扰。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

