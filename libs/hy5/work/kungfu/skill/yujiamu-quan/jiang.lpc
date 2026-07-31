// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JIANG "「" HIR "修罗降世" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        int angry;
        string msg;
        int skill, ap, dp, damage;

                 

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(JIANG "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JIANG "只能空手施展。\n");

        skill = me->query_skill("yujiamu-quan", 1);

        if (skill < 100)
                return notify_fail("你金刚瑜迦母拳修为不够，难以施展" JIANG "。\n");

        if (me->query_skill_mapped("cuff") != "yujiamu-quan")
                return notify_fail("你没有激发金刚瑜迦母拳，难以施展" JIANG "。\n");



        if (me->query("neili") < 180)
                return notify_fail("你目前的真气不足，难以施展" JIANG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        if (angry = me->query("qi") < me->query("max_qi") / 2)
                msg = HIR "$N" HIR "目睚俱裂，一声爆喝，全身骨骼劈啪作响，拳"
                      "头如闪电般击向$n" HIR "的要害！\n" NOR;
        else
                msg = HIR "$N" HIR "大喝一声，面色赤红，全身骨骼劈啪作响，拳"
                      "头如闪电般击向$n" HIR "的要害！\n" NOR;

        ap = me->query_skill("cuff", 1);
        dp = target->query_skill("dodge", 1);
             
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                me->start_busy(1);
                damage = me->query_skill("cuff", 1);
                if (angry) damage += random(damage / 2);
                damage = 150 + damage;
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "结果$p" HIR "无法抵挡$P" HIR "这雷"
                                           "霆一击，登时被打退数步，摇晃不定。\n" NOR;
                                           

        } else
        {
                me->add("neili",-40);
                msg += CYN "可是$p" CYN "并未被这气势所慑，轻移"
                       "脚步，躲开了$P" CYN "的攻击。\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

