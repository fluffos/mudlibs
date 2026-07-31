// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define PO "「" HIW "骄阳劈天" NOR "」"

inherit F_SSERVER;


string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp,i;
        int damage;

   

        if (! target) target = offensive_target(me);
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对，难以施展" PO "。\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < 220)
                return notify_fail("你的九阳神功不够娴熟，难以施展" PO "。\n");

        if ((int)me->query_skill("force", 1) < 260)
                return notify_fail("你的内功根基不够，难以施展" PO "。\n");

        if ((int)me->query_skill("blade", 1) < 260)
                return notify_fail("你的基本刀法火候不够，难以施展" PO "。\n");

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("你的内力修为不足，难以施展" PO "。\n");

        if (me->query("neili") < 400)
                return notify_fail("你现在真气不够，难以施展" PO "。\n");

        if (me->query_skill_mapped("blade") != "jiuyang-shengong") 
                return notify_fail("你没有激发九阳神功为刀法，难以施展" PO "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "\n$N" HIW "猛然间飞身而起，半空中一声长啸，内力源源不绝地涌"
              "入" + weapon->name() + HIW "，刹那间刀芒夺目，自天而下，劈向$n" HIW "！\n" NOR;

        me->add("neili", -150);
        ap = me->query_skill("force") + me->query_skill("force", 1);
        dp = me->query_skill("parry") + target->query_skill("force", 1);

        me->start_busy(2 + random(2));
        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = me->query_skill("force")*2;
                me->add("neili", -100);
target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
        target->add("neili", -(damage/2 ));
        target->add("neili", -(damage/2 ));		
                msg += HIR "$n" HIR "只觉刀芒夺目，正犹豫间到刀芒已穿透$n" HIR "身体，顿时"
                "鲜血狂涌，内息散乱。\n" NOR;
        } else
        {
                msg += HIC "可是$n" HIC "看透$P" HIC "此招之中的破绽，镇"
                       "定逾恒，全神应对自如。\n" NOR;
        }
        message_vision(msg, me, target);
if (random(me->query("combat_exp",1))> target->query("combat_exp",1)/3  && me->query("jiuyangok"))
 {
 me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 2200);
        for (i = 0; i < 5; i++)
        {

                if (random(3) ==0 )
                        target->start_busy(3);

COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2200);
}
        return 1;
}

string final(object me, object target, int damage)
{
        target->add("neili", -(damage / 4));
        target->add("neili", -(damage / 8));
        return  HIR "$n" HIR "只觉刀芒夺目，正犹豫间到刀芒已穿透$n" HIR "身体，顿时"
                "鲜血狂涌，内息散乱。\n" NOR;
}


