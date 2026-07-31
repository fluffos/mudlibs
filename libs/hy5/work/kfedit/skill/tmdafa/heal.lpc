// heal.c



#include <ansi.h>



int exert(object me, object target)

{

        if( me->is_fighting() )

                return notify_fail("战斗中运功疗伤？找死吗？\n");



        if ((int)me->query_skill("tmdafa", 1) < 20)

                return notify_fail("你的天魔大法修为还不够。\n");

        if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )

                return notify_fail("你的真气不够。\n");



        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )

                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");



        write( HIW "你默运内力，一股暖流透遍全身，受伤紊乱的内息迅速平复。\n" NOR);

        message("vision",

                HIW + me->name() + "原先混乱的气息慢慢地平复了，看来伤势好了不少。\n" NOR,

                environment(me), me);



        me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );

        me->add("neili", -50);

        me->set("jiali", 0);



        return 1;

}