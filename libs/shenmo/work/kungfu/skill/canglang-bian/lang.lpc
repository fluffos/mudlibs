// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
      
#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 
  

int perform(object me, object target) 
{ 
        object weapon; 
        int skill; 
        
        if (! target) target = offensive_target(me); 

        if (! target 
        ||      ! target->is_character() 
        ||      ! me->is_fighting(target)) 
                return notify_fail("「巨浪滔天」只能对战斗中的对手使用。\n"); 

        if (! objectp(weapon = me->query_temp("weapon"))  
        ||      (string)weapon->query("skill_type") != "whip")  
                return notify_fail("你没有鞭在手，施不出「巨浪滔天」。\n");  

        if ((int)me->query("neili") < 200)  
                return notify_fail("你的内力不够！\n");  

        if (me->query_skill("canglang-bian", 1) < 50)  
                return notify_fail("你的「沧浪鞭法 」未臻高妙境界，无法施出「巨浪滔天」！\n");  

        if (me->query_skill("bibo-shengong", 1) < 50)  
                return notify_fail("你的碧涛玄功修为不够，无法施出「沧浪鞭法」！\n");  

        if (me->query_skill_mapped("whip") != "canglang-bian")  
                return notify_fail("你所用的并非「沧浪鞭法 」，施展不出「巨浪滔天」！\n");  

        if (me->query_temp("julang") )  
                return notify_fail("你已经正在施展「巨浪滔天」了！\n");  

        message_combatd(
                HIR "$N忽然将" + (me->query_temp("weapon"))->query("name") + 
                HIR "频频甩出，" + (me->query_temp("weapon"))->query("name") + 
                HIR "发出劈啪暴空之声不绝扰得$n心烦意乱。\n" NOR, me, target);   
        message_combatd(
                HIB "$N的招数万千，但鞭头却总是指向$n的周身要穴，攻击如巨浪连绵无穷无尽，"
                "令$n只有招架之功却无还手之力。\n" NOR, me, target); 

        me->set_temp("julang", 1); 

        skill =  ( me->query_skill("canglang-bian") + me->query_skill("dodge") ) / 4; 

        me->add_temp("apply/attack", 100); 
        me->add_temp("apply/defense",  100); 

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -200); 
        me->start_busy(random(2)); 

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill/5); 

        return 1; 
} 
      
private int remove_effect(object me, int amount) 
{ 
        if ((int)me->query_temp("julang"))
        {
                me->add_temp("apply/attack", -100); 
                me->add_temp("apply/defense", -100); 
                me->delete_temp("julang"); 
                message_combatd(YEL "\n$N慢慢内运内功，把真气压下！\n\n" NOR, me);
        }

        return 0; 
} 
