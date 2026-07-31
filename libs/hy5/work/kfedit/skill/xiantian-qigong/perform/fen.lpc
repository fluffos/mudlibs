// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define FEN "「" HIW "五阴焚灭" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage,i;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(FEN "只能空手施展。\n");

        if ((int)me->query_skill("xiantian-qigong", 1) < 240)
                return notify_fail("你的先天功修为不够，难以施展" FEN "。\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("你的内力修为不足，难以施展" FEN "。\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
        if (me->query_skill_mapped("unarmed") != "xiantian-qigong")
                return notify_fail("你没有激发先天功为拳脚，难以施展" FEN "。\n");

        if (me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("你没有激发先天功为内功，难以施展" FEN "。\n");



        if (me->query("neili") < 600)
                return notify_fail("你现在的真气不足，难以施展" FEN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "体内先天真气急速运转，单掌一抖，掌心顿时升起一个气"
              "团，朝$n" HIW "猛拍而去。\n" NOR;

        ap = me->query_skill("unarmed") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("force");

        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        me->start_busy(2);
                        msg += HIR "$n" HIR "正直诧异间，$N" HIR "一掌已正中$p"
                               HIR "脑门，先天真气登时贯脑而入。\n" NOR "( $n"
                               RED "受伤过重，已经有如风中残烛，随时都可能断气"
                               "。" NOR ")\n";
                        damage = -1;
                } else
                {
                        me->start_busy(4);
                        damage = me->query_skill("unarmed");
                        me->add("neili", -500);
		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=   HIR "结果$N" HIR "这掌正中$n" HIR "胸"
                                                   "口，先天真气登时透体而入，接连喷出数"
                                                   "口鲜血。\n" NOR;
                        
                }
        } else
        {
                me->start_busy(3);
                me->add("neili", -120);
                msg += CYN "可是$p" CYN "识破了$P"
                       CYN "这一招，斜斜一跃躲避开来。\n" NOR;
        }
        message_combatd(msg, me, target);

if (random(me->query("combat_exp",1)) >= target->query("combat_exp",1)/3)
{
 msg = HIR "紧接着$N" HIR "十指纷飞，接连弹出数道无形剑气，$n" HIR "四面八"
              "方皆被剑气所笼罩。\n"NOR;
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 1800);
        for (i = 0; i < 5; i++)
        {

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(3);

COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }

        me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1800);
}

        return 1;
}
