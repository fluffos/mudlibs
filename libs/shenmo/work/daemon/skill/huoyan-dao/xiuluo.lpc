// by snowman

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
      int i, jiali;

       if( !target ) target = offensive_target(me);
       if( !target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「修罗焰」攻击只能对战斗中的对手使用。\n");

       if (me->query_temp("weapon"))
           return notify_fail("「修罗焰」是空手绝技，你拿着武器是使不出来的！\n");

        if(me->query_skill("huoyan-dao", 1) < 130 )
                return notify_fail("你的火焰刀火候还嫌不够，这「修罗焰」绝技不用也罢。\n");

        if(me->query_skill("strike", 1) < 130 )
                return notify_fail("你的基本掌法还不够娴熟，使不出「修罗焰」绝技。\n");

        if( (int)me->query_con() < 34)
                return notify_fail("你的身体还不够强壮，强使「修罗焰」绝技是引火自焚！\n");

        if(userp(me) && (int)me->query_skill("xiaowuxiang", 1) < 100 )
                return notify_fail("你的小无相功等级不够高，使不出「红莲火」。\n");

       if (me->query("max_neili") < 1500)
           return notify_fail("你的内力修为不够，这「修罗焰」绝技不用也罢。\n");

       if (me->query("neili") < 1000)
           return notify_fail("以你目前的内力来看，这「修罗焰」绝技不用也罢。\n");

       if (me->query("jing") < 200)
           return notify_fail("你的精力不够。\n");
       if(me->query_temp("combat_yield"))
           return notify_fail("哦。。。你现在正打不还手呢。\n");

        me->add("neili", -200);
     
        message_vision(HIR"\n突然$N双掌搓了几搓，只听得嗤嗤声响，「火焰刀」在$P极强内劲的斗然冲击之下威势大盛，激射而出的无形刀气组成了一片刀网，宛如修罗降世，向着$n直劈而下！\n"NOR,me,target);      

        i = me->query_skill("force") / 2 * (3+random(6));        
        jiali = me->query("jiali");

        me->set("jiali", i);
        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 500);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -500);
        me->set("jiali", jiali);
        if(!me->query_temp("xiuluo")) me->add("neili", -50);
        else me->delete_temp("xiuluo");

        me->start_busy(2);
        return 1;
}

