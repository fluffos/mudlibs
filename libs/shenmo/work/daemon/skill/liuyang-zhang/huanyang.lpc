// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUAN "「" HIR "寰阳式" NOR "」"

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
                return notify_fail(HUAN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUAN "只能空手施展。\n");

        if (me->query_skill("force") < 200)
                return notify_fail("你的内功火候不够，难以施展" HUAN "。\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 130)
                return notify_fail("你的天山六阳掌不够娴熟，难以施展" HUAN "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你的真气不够，难以施展" HUAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "双掌一振，施出天山六阳掌「寰阳式」，幻出"
              "满天掌影，团团罩住$n" HIR "。\n" NOR;

        me->add("neili", -50);
        
        ap = me->query_skill("strike"); 
        dp = target->query_skill("force"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
                me->add("neili", -200);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "见躲闪不得，只能硬挡下一"
                                           "招，顿时被$P" HIR "震得连退数步，吐血"
                                           "不止！\n" NOR;
                me->start_busy(3);
        } else
        {
                me->add("neili", -100);
                msg += HIC "可是$p" HIC "强运内力，硬生生的挡住$P"
                       HIC "这一掌，没有受到任何伤害。\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

