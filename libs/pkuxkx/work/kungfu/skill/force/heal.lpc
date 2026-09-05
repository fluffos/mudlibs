// heal.c所有的内功都可以heal
// Modified by whuan 2007-9-28
#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
           return notify_fail("战斗中运功疗伤？找死吗？\n");

    if ((int)me->query_skill("force") < 30)
           return notify_fail("你的内功修为还不够。\n");
    if( (int)me->query("neili") < 50 )
           return notify_fail("你的真气不够。\n");

    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
           return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

    write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
    message("exert",
                HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
           environment(me), me);

    me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
    me->add("neili", -50);
    me->set("jiali", 0);
    me->start_busy(random(2));
    return 1;
}
