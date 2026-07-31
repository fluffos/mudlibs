
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[天马行空]只能在战斗中使用。\n");

        if((int)me->query_skill("shenkong-xing",1) < 60)
                return notify_fail("你的身空行不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = "$N！使出身空行，身形回转，如天马跃空而行，向$n攻去！\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += NOR "结果$p被$P绕得不知所措！\n" NOR;
                target->start_busy(4);
                me->add("neili", -100);
                       } else {
                msg +=  "结果$P自己绕了个头晕眼花。\n";
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
