// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// gu.c 孤注一掷

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        damage = me->query_skill("strike");

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「孤注一掷」只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「孤注一掷」！\n");              

        if( (int)me->query_skill("huixin-strike", 1) < 60 )
                return notify_fail("你的峨嵋催心掌不够娴熟，不会使用「孤注一掷」!\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用「孤注一掷」!\n");

        msg = CYN "$N默运神功，使出「"RED"孤注一掷"CYN"」，双掌平推攻向$n。\n"NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(random(2));
                target->start_busy(random(3));

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);

                if( damage < 40 )
                        msg += HIY"结果$n被$N双掌打在胸口，闷哼一声。\n"NOR;
                else if( damage < 80 )
                        msg += HIY"结果$n被$N以双掌打在胸口，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 160 )
                        msg += RED"结果$n被$N以双掌打在胸口，有如受到一记重锤，连退了五六步！\n"NOR;
                else
                        msg += HIR"结果$n被$N的双掌打在胸口，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
                
        }
        else 
        {
                me->start_busy(1 + random(2));
                msg += CYN"可是$p看破了$P的企图，身形一转，反掌回击。\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
