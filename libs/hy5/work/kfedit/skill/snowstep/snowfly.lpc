// lingbo.c  lingxiao

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("只有在打斗中才能使用!\n");



        if((int)me->query_skill("bingxue-xinfa",1) < 100)
                return notify_fail(HIY "你的冰雪心法修为不够。\n" NOR);

         if((int)me->query_skill("snowstep",1) < 100)
                return notify_fail(HIY "你的梅雪飘香不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if( me->query("gender") == "男性")
               {msg = HIW
"$N如柳絮般轻轻飘起。四面八方都是$N的影子,虚虚实实,不知哪个才是真的。\n" NOR;}
        else   {msg = HIY 
"$N如柳絮般轻轻飘起。四面八方都是$N的影子,虚虚实实,不知哪个才是真的。\n" NOR;}

        if( (random(me->query("combat_exp"))+(int)me->query_skill("snowstep",1)*800) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "结果$p被$P的动作吓得目瞪口呆！\n" NOR;
target->start_busy( (int)me->query_skill("snowstep",1) / 50+2);
//                target->start_busy(6);
                me->add("neili", -100);
                       } else {
                msg +=  "$p只是勉强的逃了开去。\n";
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
