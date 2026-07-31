// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{      
        object weapon;
        object obj;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/liancheng-jianfa/qujian"))
                return notify_fail("你还没有受过高人指点，无法施展「去剑势」。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("去剑势只能对对手使用。\n");
        
        if( me->query_skill("liancheng-jianfa") < 80 )
                return notify_fail("你的连城剑法不够娴熟，不能施用去剑势。\n");
                
        if( !objectp(weapon = target->query_temp("weapon")) )
                return notify_fail("对手并没有使用武器。\n");
                
        msg = "$N清啸一声，抖直手中的兵刃，以连城剑法的去剑势顺势搭上了$n的兵器！\n";
        
        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");

        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(1);
                msg += HIY "只听得一阵金铁交鸣之声，结果$p的兵刃被$P手中的兵器一连一带，远远地飞了开去！\n" NOR;
                obj = target->query_temp("weapon");
                destruct(obj);
                target->start_busy(1 + random(4));
        } else 
        {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}
