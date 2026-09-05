// lingbo.c  洛神凌波

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("你一个人跳甚么？\n");

        if( me->query("gender") == "无性")
                return notify_fail(HIY "一个公公，满场乱跳，羞也不羞？\n" NOR);

        if((int)me->query_skill("beiming-shengong",1) < 100)
                return notify_fail(HIY "你的北冥神功修为不够。\n" NOR);

        if((int)me->query_skill("lingboweibu",1) < 100)
                return notify_fail(HIY "你的凌波微步不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if( me->query("gender") == "男性")
               {msg = YEL
"$N提起真气，意态飘逸,一招落神凌波,如入无人之境！\n" NOR;}
        else   {msg = YEL 
"$N提起真气，施展凌波微步，仿如洛神再生，仙女下凡！\n" NOR;}

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += HIW "结果$p被$P的舞步吓得目瞪口呆！\n" NOR;
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
