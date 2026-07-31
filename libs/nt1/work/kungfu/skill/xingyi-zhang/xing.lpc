// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int i, ap, dp; 
        
        if (userp(me) && ! me->query("can_perform/xingyi-zhang/xing"))
                return notify_fail("你还没有受过高人指点，无法施展「星光点点」。\n");
        
        i = me->query_skill("xingyi-zhang", 1)/5;        
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「星光点点」只能在战斗中对对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("使用「星光点点」时双手必须空着！\n");

        if( (int)me->query_skill("xingyi-zhang", 1) < 120 )
                return notify_fail("你的星移掌不够娴熟，不会使用「星光点点」。\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 120 )
                return notify_fail("你的神元功等级不够，不能使用「星光点点」。\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("你的身法不够强，不能使用「星光点点」。\n");

        if (me->query_skill_prepared("strike") != "xingyi-zhang"
                || me->query_skill_mapped("strike") != "xingyi-zhang")
                return notify_fail("你现在无法使用「星光点点」进行攻击。\n");                                                                                
      

        if( (int)me->query("neili") < 700 )
                return notify_fail("你现在内力太弱，不能使用「星光点点」。\n"); me->add("neili", -300);

        message_combatd(HIW "\n$N双掌交相呼应,漫天的掌影犹如星星般在$n周围闪烁不定！\n" NOR,me, target);

        me->add_temp("apply/str", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK); 
        if( (int)me->query_str() >(int)target->query_str()/2) 
        {
                me->add_temp("apply/str", i);
                me->add_temp("apply/attack", i);
                me->add_temp("apply/damage", i); 
                msg =  HIW"$N将神元神功发挥到极限，一双手掌发出耀眼的光芒，幻化出漫天掌影！" NOR; 
                message_combatd(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK); 
                me->add("neili", -100);    
                me->add_temp("apply/str", -i);
                me->add_temp("apply/attack", -i);
                me->add_temp("apply/damage", -i);       
        } 
        me->add("neili", -400); 
        me->add_temp("apply/damage", -i); 
        me->add_temp("apply/str", -i);
        me->add_temp("apply/attack", -i);  
        me->start_busy(1+random(2));        
        return 1;
}
