
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[蟾飞九天]只能在战斗中使用。\n");

        if((int)me->query_skill("chanchu-bufa",1) < 60)
                return notify_fail("你的蟾蜍步法不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIM"$N一招「蟾飞九天」，身体向上笔直地纵起丈余，饶着$n不停的急转！\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR"结果$p被$P绕得不知所措！\n" NOR;
                target->start_busy( (int)me->query_skill("chanchu-bufa",1) / 50 + 2 );
                me->add("neili", -60);
                       } else {
                msg +=  HIC"结果$P自己绕了个头晕眼花。\n"NOR;
                me->add("neili", -60);
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}
