// heal.c
#include <ansi.h>
int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");
        if ((int)me->query_skill("hamagong", 1) < 20)
                return notify_fail("你的蛤蟆功修为还不够。\n");
        if( (int)me->query("neili") < 250 ) // - (int)me->query("max_neili") < 50 )
                return notify_fail("你的真气不够。\n");
        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        write( HIB "你暗运蛤蟆功，真气游走于全身上下，各处伤痛大为好转。\n" NOR);
        message("vision",
                HIB + me->name() + "喉咙中发出“咕咕”的声音，脸色忽青忽白，随即恢复正常。\n" NOR,
                environment(me), me);
        me->receive_curing("qi", (int)me->query_skill("force")/3 );
        me->receive_curing("jing", (int)me->query_skill("force")/6 );
        me->add("neili", -150);
        me->set("jiali", 0);
        me->start_busy(1);
        return 1;
}
