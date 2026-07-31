
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[沧海一笑]只能在战斗中使用。\n");

        if((int)me->query_skill("xiaoyaoyou",1) < 70)
                return notify_fail("你的逍遥游不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前已经很忙了！\n");

	msg = BLU"$N强提真气，身法突变得迷离，有如纵横之式，吸取沧海之灵气，一步千里！\n" NOR;
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
