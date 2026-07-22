// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// fenglei.c

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, msg1;
        int i, z;
        object weapon;
        z = me->query_skill("luoying-shenjian", 1) / 2;
        
        if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail("「风雷四神剑」只能在战斗中对对手使用。\n");
                
        if (userp(me) && ! me->query("can_perform/luoying-shenjian/fenglei"))
                return notify_fail("你还没有受到高人指点，暂时还不会施展「风雷四神剑」！\n");
                
        weapon = me->query_temp("weapon");
        if (! weapon || weapon->query("skill_type") != "sword"
        ||  me->query_skill_mapped("sword") != "luoying-shenjian")
                return notify_fail("你必须使用在剑时才能使出「风雷四神剑」！\n");

        if ((int)me->query_skill("luoying-shenjian", 1) < 80)
                return notify_fail("你的落英神剑不够娴熟，不会使用「风雷四神剑」。\n");

        if ((int)me->query_skill("bibo-shengong", 1) < 60)
                return notify_fail("你的碧波神功修为不够，不能使用「风雷四神剑」。\n");

        if ((int)me->query_dex() < 30)
                return notify_fail("你的身法太低，不能使用「风雷四神剑」。\n");

        if (me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("你使用的内功不对，不能使用「风雷四神剑」。\n");

        if ((int)me->query("neili", 1) < 400)
                return notify_fail("你现在内力太弱，不能使用「风雷四神剑」。\n");

        i = (me->query_skill("luoying-shenjian", 1) / 4);
        
        msg = HIG "$N高声长吟：“桃花影里飞神剑”，如风如雷般的发出数剑! \n" NOR;
        msg1 = HIY"$N使完风雷绝技，感到内力消耗不少。\n" NOR;
       
        me->add_temp("apply/damage", z); 
        me->add_temp("apply/str", z/10);
        me->add_temp("apply/attack", z); 
        message_combatd(msg, me, target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(WHT"                                                                           风字诀\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(HIC"                                                                           雨字诀\n"NOR,me); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(MAG"                                                                           雷字诀\n"NOR,me); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_combatd(HIR"                                                                           电字诀\n"NOR,me);
        me->add("neili", -200);
       
        me->start_busy(2);
        me->add_temp("apply/damage", -z);
        me->add_temp("apply/str", -z/10);
        me->add_temp("apply/attack", -z); 
        message_combatd(msg1, me,target);

        return 1;
}

