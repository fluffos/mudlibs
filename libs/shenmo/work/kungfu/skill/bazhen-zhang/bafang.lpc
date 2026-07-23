// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// bafang.c 威镇八方
         
#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 

         
int perform(object me, object target) 
{ 
        object weapon; 
        string msg; 
        int ap, dp; 
        int damage; 
                        
        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail("「威镇八方」只能在战斗中对对手使用。\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("你必须空手才能使用「威镇八方」！\n"); 
         
        if (me->query_skill("force") < 300) 
                return notify_fail("你的内功的修为不够，不能使用这一绝技！\n"); 
        
        if (me->query_skill("bazhen-zhang", 1) < 200) 
                return notify_fail("你的这门武功修为不够，目前不能使用「威镇八方」！\n"); 
         
        if (me->query("neili") < 700) 
                return notify_fail("你的真气不够，无法使用「威镇八方」！\n"); 
         
        if (me->query_skill_mapped("strike") != "bazhen-zhang") 
                return notify_fail("你没有激发这门武功，不能使用「威镇八方」！\n"); 
         
        msg = HIY "$N" HIY "深深的吸了一口气，大喝一声，全身衣袍无风自鼓，" 
                   HIY "然后提气往上一纵，居高临下，双掌奋力击下，刹那间，内劲犹如旋风般"
                   "击向$n" + HIY "！\n" NOR; 
         
        ap = me->query_skill("strike") + me->query("str") * 20;
        dp = target->query_skill("parry") + target->query("dex") * 20;
        
        if (ap / 2 + random(ap) > dp)
        { 
                damage = me->query_skill("strike");
                me->add("neili", -350); 
         
target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);
target->apply_condition("zhua_poison",10);

                        msg +=                 HIR "只见$n" HIR "大吃一惊，仓皇之下不及闪躲，被$N"
                                           HIR "一掌打了个正中，闷哼一声，连退数步！\n" NOR;
        } else 
        { 
                me->add("neili", -100); 
                me->start_busy(3); 
                msg += CYN "可是$p" CYN "看破了$N" CYN "的企图，轻轻" 
                       CYN "向后飘出数丈，躲过了这一致命的一击！\n"NOR; 
        } 
        message_combatd(msg, me, target); 
	      msg = HIC  "威镇东方！$N从东方打来一掌！" NOR;
	      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "威镇西方！$N从西方打来一掌！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "威镇南方！$N从南方打来一掌！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "威镇北方！$N从北方打来一掌！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "威镇上方！$N从上方打来一掌！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "威镇下方！$N从下方打来一掌！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);         
        msg = HIY  "威镇前方！$N从前方打来一掌！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);         

        msg = CYN  "威镇后方！$N从后方打来一掌！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);         
                me->start_busy(3);
                me->add("neili", -380);
        return 1; 
}
