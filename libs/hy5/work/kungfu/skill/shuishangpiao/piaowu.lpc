// lingbo.c  铁掌漂舞

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("你一个人跳甚么？\n");


        if((int)me->query_skill("guiyuan-tunafa",1) < 100)
                return notify_fail(HIY "你的归元吐纳法修为不够。\n" NOR);

         if((int)me->query_skill("shuishangpiao",1) < 100)
                return notify_fail(HIY "你的水上漂不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if( me->query("gender") == "男性")
               {msg = HIG
"$N一招「落叶随风」，身体如一片落叶一般飘了出去，身行之潇洒，迅速到了极处。\n" NOR;}
        else   {msg = HIC 
"$N一招「落叶随风」，身体如一片落叶一般飘了出去，仙女下凡！\n" NOR;}

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIW "结果$p被$P的动作吓得目瞪口呆！\n" NOR;
                target->start_busy(6);
                me->add("neili", -100);
                       } else {
                msg +=  "$p只是勉强的逃了开去。\n";
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
