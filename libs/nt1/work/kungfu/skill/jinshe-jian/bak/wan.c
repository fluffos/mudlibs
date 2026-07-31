// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        int extra,i,time;
        string msg;
        
        extra = me->query_skill("jinshe-jian",1);
        time = extra/40; 
        
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「金蛇万道」只能在战斗中使用。\n");
                
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
                        
        if( (string)weapon->query("id") != "jinshe jian" )
                return notify_fail("没有金蛇剑又怎能使出金蛇剑法的独门招式【金蛇万道】？\n");
                
        if((int)me->query_skill("sword") <200)
                return notify_fail("你的剑法修为不够， 目前不能使用【金蛇万道】! \n");
                
        weapon = me->query_temp("weapon");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够！\n");
                
        msg = HIR  "$N猛吸一口真气，眼中神光大盛，手中的"+ weapon->name()+  HIR"急速挥舞，化作万道金虹向$n卷来！" NOR;
        message_combatd(msg,me,target);
        me->add_temp("apply/attack",extra/5);
        me->add_temp("apply/damage",extra/5);
        for(i=1;i<=(int)time;i++)
        {
                // msg =  YEL "$N眼中寒意幽幽，将金蛇万道发挥到最高境界！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        }
        me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/5);
        me->add("neili",-500);
        me->start_busy(3);
        return 1;
}

