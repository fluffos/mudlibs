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
        string msg; 
        int ap, dp; 
        int damage; 

        if (userp(me) && ! me->query("can_perform/xiuluo-zhi/jueming"))
                return notify_fail("你还没有受过高人指点，无法施展「修罗绝命指」。\n");
                        
        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail("「修罗绝命指」只能在战斗中对对手使用。\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("你必须空手才能使用「修罗绝命指」！\n"); 
         
        if (me->query_skill("force") < 250) 
                return notify_fail("你的内功的修为不够，不能使用「修罗绝命指」！\n"); 
        
        if (me->query_skill("xiuluo-zhi", 1) < 150) 
                return notify_fail("你的修罗指修为不够，目前不能使用「修罗绝命指」！\n"); 
         
        if (me->query("neili") < 500) 
                return notify_fail("你的真气不够，无法使用「修罗绝命指」！\n"); 
         
        if (me->query_skill_mapped("finger") != "xiuluo-zhi") 
                return notify_fail("你没有激发修罗指，不能使用「修罗绝命指」！\n"); 
         
        msg = HIB "$N忽然面露凶光，身形变的异常飘渺，在$n" HIB
                  "的四周游走个不停，$n" HIB "正迷茫时，$N" HIB
                  "突然近身，毫无\n声息的一指戳出！\n" NOR; 
         
        ap = ap_power(me, "finger") + me->query_skill("force"); 
        dp = dp_power(target, "dodge") + target->query_skill("parry"); 
         
        if (ap / 2 + random(ap) > dp) 
        { 
                damage = da_power(me, "finger");
                me->add("neili", -350); 
         
                msg += HIR "只见$n" HIR "一声惨叫，以被击中要害部位，只觉得眼前一黑，似乎以看不清周围的一切，身体摇摇欲坠！\n" NOR;
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 100); 
        } else 
        { 
                me->add("neili", -150); 
                msg += CYN "可是$n" CYN "看破了$N" CYN "的企图，轻轻" 
                       CYN "向后飘出数丈，躲过了这一致命的一击！\n"NOR; 
        } 
        message_combatd(msg, me, target); 
         
        me->start_busy(3); 
        return 1; 
}

