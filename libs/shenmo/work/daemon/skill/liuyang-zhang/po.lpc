// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define PO "「" HIR "破神诀" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(PO "只能空手施展。\n");

        if ((int)me->query_skill("bahuang-gong", 1) < 220
                && (int)me->query_skill("beiming-shengong", 1) < 220)
                return notify_fail("你的本门火候不够，难以施展" PO "。\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 220)
                return notify_fail("你的天山六阳掌不够娴熟，难以施展" PO "。\n");

        if (me->query("max_neili") < 3500)
                return notify_fail("你的内力修为不足，难以施展" PO "。\n");

        if (me->query_skill_mapped("force") != "bahuang-gong"
                && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有激发本门内功，难以施展" PO "。\n");

        if (me->query("neili") < 800)
                return notify_fail("你现在真气不足，难以施展" PO "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "将八荒六合唯我独尊功提运至极限，全身真气迸发，呼的一掌"
              "向$n" HIR "头顶猛然贯落。\n" NOR;

        me->add("neili", -500);
        ap = me->query_skill("strike") + me->query_skill("force"); 
        dp = target->query_skill("parry") + target->query_skill("force"); 
        
        //if (target->is_good()) ap += ap / 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "顿时只听“噗”的一声，$N" HIR "一掌将$n"
                               HIR "头骨拍得粉碎，脑浆四溅，当即瘫了下去。\n"
                               NOR "( $n" RED "受伤过重，已经有如风中残烛，"
                               "随时都可能断气。" NOR ")\n";
                        damage = -1;
                } else
                {
                        damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "慌忙抵挡，可已然不及，$N"
                                                   HIR "掌劲如洪水般涌入体内，接连震断数根"
                                                   "肋骨。\n" NOR;

                       
                }
                me->start_busy(3);
        } else
        {
                msg += CYN "$p" CYN "见$P" CYN "掌劲澎湃，决计抵挡不"
                       "住，当即身子向后横丈许，躲闪开来。\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);



        return 1;
}

