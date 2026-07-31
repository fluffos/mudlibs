// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHI "「" HIW "七星指穴" NOR "」"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int skill;

        if (userp(me) && ! me->query("can_perform/canhe-zhi/zhi"))
                return notify_fail("你还没有受过高人指点，无法施展" ZHI "。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(ZHI "只能对战斗中的对手使用。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        skill = me->query_skill("canhe-zhi", 1);

        if (skill < 120)
                return notify_fail("你的参合指修为有限，难以施展" ZHI "。\n");

        if (me->query("neili") < 150)
                return notify_fail("你的真气不够，难以施展" ZHI "。\n");

        if (me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("你没有激发参合指, 难以施展" ZHI "。\n");

        if (me->query_skill_prepared("finger") != "canhe-zhi")
                return notify_fail("你现在没有准备使用参合指, 难以施展" ZHI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIG "$N" HIG "一声冷哼，右手中食两指并拢，斜斜指出，朝$n"
              HIG "凌空虚点七下。\n" NOR;

        me->add("neili", -120);
        me->start_busy(1);
        ap = ap_power(me, "finger");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "结果只听“噗噗噗”数声，$p" HIR "竟被$P"
                       HIR "以指力封住穴道，动弹不得。\n" NOR;
                target->start_busy(ap / 200 + random(4));
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P"
                       CYN "的企图，轻轻一跃，躲开了这一招。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

