// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define GUANG "「" HIY "光华令" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage, skill, ap, dp;
        string msg;



        if (! target) target = offensive_target(me);

        skill = me->query_skill("shenghuo-ling",1);

        if (! (me->is_fighting()))
                return notify_fail(GUANG "只能对战斗中的对手使用。\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的兵器不对，不能使用圣火令法之" GUANG "。\n");

        if (skill < 140)
                return notify_fail("你的圣火令法等级不够, 不能使用圣火令法之" GUANG "。\n");

        if (me->query("max_neili") < 1500)
                return notify_fail("你的内力修为不足，不能使用圣火令法之" GUANG "。\n");

        if (me->query("neili") < 340)
                return notify_fail("你的内力不够，不能使用圣火令法之" GUANG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "猛吸一口气，使出圣火令法之「" HIW "光华令" HIY "」，手中"
              + weapon->name() + NOR + HIY "御驾如飞，幻出无数道金"
              "芒，将$n" HIY "笼罩起来！\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword")*2;

                me->add("neili", -300);
       target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "只觉万道金芒铺天盖地席卷而来，"
                       "完全无法阻挡。顿时只感全身几处刺痛，鲜血飞"
                       "溅而出！\n" NOR;

                me->start_busy(2);
        } else
        {
                msg += CYN "可是$n" CYN "看准$N" CYN "的破绽，猛地向"
                       "前一跃，跳出了$N" CYN "的攻击范围。\n"NOR;
                me->add("neili", -150);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
