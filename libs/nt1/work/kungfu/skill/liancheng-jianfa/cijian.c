// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h> 
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

#include "/kungfu/skill/eff_msg.h"; 

string *limbs = ({ 
        "头部", "颈部", "胸口", "后心", "左肩", "右肩", "左臂", 
        "右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿", 
        "左脚", "右脚", "左耳", "右耳", "左脸", "右脸", 
}); 

void remove_effect(object target);
string *songs = ({"HIC", "HIR", "HIW", "HIY"});
        
int perform(object me, object target) 
{ 

        int damage, p, ap, dp; 
        object weapon; 
        string msg, song, dodge_skill; 

        if (userp(me) && ! me->query("can_perform/liancheng-jianfa/cijian"))
                return notify_fail("你还没有受过高人指点，无法施展「"HIM"刺肩式"NOR"」。\n");
                
        song = songs[random(sizeof(songs))];

        if( !target ) target = offensive_target(me); 

        weapon = me->query_temp("weapon"); 
        if( !target ) 
                target = offensive_target(me); 

        if( !target || !me->is_fighting(target) ) 
                return notify_fail("「"HIM"刺肩式"NOR"」只能在战斗中对对手使用。\n"); 

        if (!weapon 
                || weapon->query("skill_type") != "sword" 
                || me->query_skill_mapped("sword") != "liancheng-jianfa") 
                return notify_fail("你手里没有剑，无法使用「"HIM"刺肩式"NOR"」！\n"); 
                
        if( (int)me->query_skill("liancheng-jianfa",1) < 150 ) 
                return notify_fail("你的连城剑法不够娴熟，不能使用「"HIM"刺肩式"NOR"」！\n"); 

        if( (int)me->query_skill("sword",1) < 150 ) 
                return notify_fail("你的基本剑法等级不够，不能使用「"HIM"刺肩式"NOR"」！\n"); 

        if( (int)me->query_skill("force", 1) < 150 ) 
                return notify_fail("你的内功等级不够，不能使用「"HIM"刺肩式"NOR"」！\n"); 

        if( (int)me->query("max_neili") < 1500 ) 
                return notify_fail("你的内力太弱，不能使用「"HIM"刺肩式"NOR"」！\n"); 

        if( (int)me->query("neili") < 700 ) 
                return notify_fail("你的内力太少了，无法使用出！\n"); 
                
        msg = WHT "\n$N身子一晃，抽起"+weapon->name()+WHT"，犹如疾风骤雨般一阵猛攻，$n挡得几招，发剑回攻，\n"
              "$N突然间"+weapon->name()+WHT"抖动，卟的一声轻响，从不可思议的角度刺向了$n的肩头\n"NOR;
              
        msg = replace_string( msg, "song", songs[random(sizeof(songs))] ); 
        
        ap = ap_power(me, "sword");
        dp = dp_power(target, "dodge");
                
        if (ap / 2 + random(ap) > dp) 
        { 
                me->start_busy(1); 
                me->add("neili", -140); 
 
                damage = da_power(me, "sword");
                
                if (target->is_busy()) damage = damage * 2;
                         
                if (target->query("shen") < 0)  damage = damage*3/2; 
                
                if (me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage); 
                        
                target->receive_damage("qi", damage/2); 
                target->receive_wound("qi", damage/4); 
                p = (int)target->query("qi")*100/(int)target->query("max_qi"); 
                msg += COMBAT_D->damage_msg(damage, "刺伤"); 
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                msg = replace_string( msg, "$w", weapon->query("name") ); 
                msg = replace_string( msg, "$l", limbs[random(sizeof(limbs))] ); 
        } 

        message_combatd(msg, me, target); 
 
        msg = HIB "\n$n横剑挡路，见$N"+weapon->name()+HIB"停滞不前，当即振剑反刺。那知$n剑尖只一抖间，"
              "$N的"+weapon->name()+HIB"如毒蛇暴起，向前一探，已点中了$n肩头。！\n"NOR; 

        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");
                
        if (ap / 2 + random(ap) > dp
                || target->is_busy()) 
        { 
                me->start_busy(1); 
                me->add("neili", -150); 
                damage = da_power(me, "sword");
                if(target->is_busy())damage=damage*2; 
                if(target->query("shen")<0)damage=damage*3/2; 
                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage); 
                target->receive_damage("qi", damage/2); 
                target->receive_wound("qi", damage/4); 
                p = (int)target->query("qi")*100/(int)target->query("max_qi"); 
                msg += COMBAT_D->damage_msg(damage, "刺伤"); 
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                msg = replace_string( msg, "$w", weapon->query("name") ); 
                msg = replace_string( msg, "$l", limbs[random(sizeof(limbs))] ); 
        } 
        message_combatd(msg, me, target); 
        
        msg = YEL "\n$N"+weapon->name()+YEL"左一刺，右一戳，每一剑都从无比怪异的方位刺出，"
              "点向$n的肩部，$n只要一出剑相攻，立时便可后发先至，刺中$n的肩头。\n"NOR; 
              
        ap = ap_power(me, "sword");
        dp = dp_power(target, "force");
                
        if (ap / 2 + random(ap) > dp
                ||target->is_busy()) 
        { 
                me->add("neili", -160); 
        
                damage = da_power(me, "sword");
                
                if(target->is_busy())damage=damage*2; 
                if(target->query("shen")<0)damage=damage*3/2; 

                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage); 
                target->receive_damage("qi", damage/3); 
                target->receive_wound("qi", damage/6); 
                p = (int)target->query("qi")*100/(int)target->query("max_qi"); 
                msg += COMBAT_D->damage_msg(damage, "刺伤"); 
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                msg = replace_string( msg, "$w", weapon->query("name") ); 
                msg = replace_string( msg, "$l", limbs[random(sizeof(limbs))] ); 
        } 
        message_combatd(msg, me, target); 

        return 1; 
} 
