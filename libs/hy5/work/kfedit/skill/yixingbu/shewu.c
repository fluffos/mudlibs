// lingbo.c  神龙

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("只有在打斗中才能使用!\n");


        if((int)me->query_skill("shenlong-xinfa",1) < 100)
                return notify_fail(HIY "你的神龙心法修为不够。\n" NOR);

         if((int)me->query_skill("yixingbu",1) < 100)
                return notify_fail(HIY "你的意形步法不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if( me->query("gender") == "男性")
               {msg = HIY
"$N模仿着蛇的动作，身形飘忽，不紧不慢，漫不经心的快走起来。\n" NOR;}
        else   {msg = HIY 
"$N模仿着蛇的动作，身形飘忽，不紧不慢，漫不经心的快走起来。\n" NOR;}

        if( random(me->query("combat_exp"))+(me->query("combat_exp")/4) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "结果$p被$P的动作吓得目瞪口呆！\n" NOR;
                target->start_busy(6);
                me->add("neili", -50);
                       } else {
                msg +=  "$p只是勉强的逃了开去。\n";
                me->add("neili", -50);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
