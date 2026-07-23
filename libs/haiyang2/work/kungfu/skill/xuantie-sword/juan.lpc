// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// juan.c 卷字诀

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage;
        int ap, dp;
        string msg;


                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("卷字诀只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query_skill("xuantie-sword", 1) < 70)
                return notify_fail("你的玄铁剑法不够娴熟，不能使用卷字诀。\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("你的内功火候不够，不能使用卷字诀。\n");

        if ((int)me->query("neili") < 100 )
                return notify_fail("你现在内力太弱，不能使用卷字诀。\n");

        if (me->query_skill_mapped("sword") != "xuantie-sword")
                return notify_fail("你没有激发玄铁剑法，不能施展卷字诀。\n");

        if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N一抖手中的" + weapon->name() + HIY "，自下而上的朝$n"
              HIY "卷了过去，曲曲折折，变化无常！\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");
             
        if (ap / 2 + random(ap) > dp)
        {
                target->start_busy(ap / 100 + 2);
                me->add("neili", -50);
                msg += YEL "$p" YEL "连忙竭力招架，一时无暇反击。\n" NOR;
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，斜跃避开了$P"
                       CYN "的攻击。\n"NOR;
                me->add("neili", -25);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
