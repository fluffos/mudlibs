#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[葵花三段]只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("[葵花三段]必须空手才能施展。\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query_skill("kuihua-zhua", 1) < 60)
                return notify_fail("你的[葵花爪]级别还不够，使用这一招会有困难！\n");

        message_vision("\n$N使出-"HIY"[葵花爪绝技]"NOR"-"BLINK HIR"葵花三段"HIG".."NOR"\n", me);



        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"葵花一段"NOR"-------"BLINK HIR"百合折\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"葵花二段"NOR"-------"BLINK HIG"轰斧阴\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"HIY"葵花三段"NOR"-------"BLINK HIR"暗勾手\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -100);

        me->start_busy(2);
        return 1;
}

