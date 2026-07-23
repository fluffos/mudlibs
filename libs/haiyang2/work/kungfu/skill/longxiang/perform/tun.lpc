// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define TUN "「" HIR "龙吞势" NOR "」"

inherit F_SSERVER;

//nherit F_CLEAN_UP;


void remove_effect(object me);

int perform(object me, object target)
{
        object weapon;
        int ap, dp, foc, damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TUN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(TUN "只能空手施展。\n");

        if (me->query_temp("long_tun"))
                return notify_fail(TUN "无法连续施展。\n");

        if ((int)me->query_skill("longxiang", 1) < 180)
                return notify_fail("你的龙象般若功修为不够，难以施展" TUN "。\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("你的内力修为不足，难以施展" TUN "。\n");

        if (me->query_skill_mapped("unarmed") != "longxiang")
                return notify_fail("你没有激发龙象般若功为拳脚，难以施展" TUN "。\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("你没有激发龙象般若功为内功，难以施展" TUN "。\n");


        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不足，难以施展" TUN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "双臂左右分张，形若龙嘴，所施正是龙象般若功绝学「"
              HIR "龙吞势" HIY "」。霎时呼\n啸声大作，但见一股澎湃无比的罡劲"
              "至$N" HIY "双掌间涌出，云贯向$n" HIY "而去。\n" NOR;

        me->set_temp("long_tun", 1);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me :), 50);

        ap = me->query_skill("unarmed")+ me->query_skill("force"); 
        dp = target->query_skill("dodge") + target->query_skill("force"); 

        if (ap / 2 + random(ap) > dp)
        {
                foc = target->query_skill("force");
                damage = ap / 2 + random(ap) + random(foc) + 150;
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "一声哀嚎，被$N" HIR "的罡"
                                               "气划中气门，真气在体内四处乱窜，惨不堪"
                                               "言。\n" NOR;

                me->start_busy(3);
                me->add("neili", -300);
        } else
        {
                me->start_busy(3);
                me->add("neili", -200);
                msg += CYN "可是$p" CYN "见$P" CYN "此招来势非凡，急"
                       "忙向后横移数尺，终于躲避开来。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

void remove_effect(object me)
{
        if (me->query_temp("long_tun"))
        {
                me->delete_temp("long_tun");
                tell_object(me, "你经过调气养息，又可以继续施展" TUN "了。\n");
        }
}


