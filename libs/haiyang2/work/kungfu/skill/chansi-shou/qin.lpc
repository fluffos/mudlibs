// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define QIN "「" HIW "缠丝擒拿" NOR "」"

inherit F_SSERVER;


string final(object me, object target, int damage);

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(QIN "只能空手施展。\n");

        skill = me->query_skill("chansi-shou", 1);

        if (skill < 120)
                return notify_fail("你缠丝擒拿手等级不够，难以施展" QIN "。\n");
 
        if (me->query_skill_mapped("hand") != "chansi-shou")
                return notify_fail("你没有激发缠丝擒拿手，难以施展" QIN "。\n");



        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不够，难以施展" QIN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "悄然贴近$n" HIW "，施出缠丝擒拿，双手忽"
              "折忽扭，或抓或甩，直琐$p" HIW "各处要脉。\n" NOR;
 
        ap = me->query_skill("hand");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -80);
                damage = me->query_skill("hand");
target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);

                        msg +=HIR "却见$n" HIR "奋力抵抗，可终究无法"
              "摆脱$N" HIR "的攻势，连中数掌，"NOR ;
              
        if (random(3) >= 1 && ! target->is_busy())
        {
                target->start_busy(4);
                msg += YEL"难以反击。\n" NOR;
        } else
                msg += HIR"鲜血狂喷。\n" NOR;

                me->start_busy(2);
        } else
        {
                msg += CYN "可是$n" CYN "的看破了$N"
                       CYN "的招式，巧妙的招架拆解，没露半点破绽。\n" NOR;
                me->add("neili", -20);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        string msg;

        msg = HIR "却见$n" HIR "奋力抵抗，可终究无法"
              "摆脱$N" HIR "的攻势，连中数掌，";

        if (random(3) >= 1 && ! target->is_busy())
        {
                target->start_busy(damage / 150);
                msg += "难以反击。\n" NOR;
        } else
                msg += "鲜血狂喷。\n" NOR;

        return  msg;
}

