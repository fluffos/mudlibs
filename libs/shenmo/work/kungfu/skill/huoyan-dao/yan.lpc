// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YAN "「" HIR "天寰神炎" NOR "」"

inherit F_SSERVER; 
 
int perform(object me, object target)
{
        object weapon;
        string msg;


        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail(YAN "只能在战斗中对对手使用。\n");
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("你必须空手才能施展" YAN "。\n");
         
        if (me->query_skill("force") < 200) 
                return notify_fail("你的内功的修为不够，无法施展" YAN "。\n");
        
        if (me->query_skill("huoyan-dao", 1) < 190) 
                return notify_fail("你的火焰刀修为不够，无法施展" YAN "。\n");
         
        if (me->query("neili") < 600 || me->query("max_neili") < 2000) 
                return notify_fail("你的真气不够，无法施展" YAN "。\n");

        if (me->query_skill_mapped("strike") != "huoyan-dao") 
                return notify_fail("你没有激发火焰刀，无法施展" YAN "。\n");





        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "一声怒嚎，狂催真气注入单掌，掌缘顿时腾起一道烈炎，接二连三朝$n"
              HIR "劈去。\n" NOR;
        message_combatd(msg, me, target);

        me->add("neili", -300);

        me->add_temp("apply/attack", 50);
        msg = HIR "第一道烈炎"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


        me->add_temp("apply/attack", 50);
        msg = HIR "第二道烈炎"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", 50);
        msg = HIR "第三道烈炎"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", 50);
        msg = HIR "第四道烈炎"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


        msg = HIR "第五道烈炎"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR "第六道烈炎"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        // 消除攻击修正
        me->add_temp("apply/attack", -200);

        me->start_busy(3);

        return 1;
}


