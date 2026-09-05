// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if ((int)me->query_skill("longxiang-boruo", 1) < 20)
                return notify_fail("你的龙象般若功修为还不够。\n");
        if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIW "你收蹑心神，屏息静气，缓缓开始运功疗伤。\n" NOR);
        message("vision",
                HIW + me->name() + "眉头微皱，缓缓吸气吐纳，苍白的脸色渐渐红润起来。\n" NOR,
                environment(me), me);

        me->receive_curing("qi", 50 + (int)me->query_skill("force")/2 );
        me->add("neili", -50);
        me->set("jiali", 0);
        me->start_busy(1);

        return 1;
}

