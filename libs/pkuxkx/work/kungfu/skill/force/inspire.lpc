// inspire.c

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
           return notify_fail("战斗中运功疗伤？找死吗？\n");

    if ((int)me->query_skill("force", 1) < 10)
           return notify_fail("你的内功等级还不够给自己疗伤。\n");
    if( (int)me->query("neili") < 50 )
           return notify_fail("你的内力不够。\n");
    if( (int)me->query("jingli") < 50 )
           return notify_fail("你的精力不够。\n");


    if( (int)me->query("eff_jing") >= (int)me->query("max_jing") )
           return notify_fail("你根本就没有受伤，疗什么伤啊！\n");

    if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 2 )
           return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

    write( HIW "你全身放松，运转真气进行疗伤。\n" NOR);
    message("exert",
           HIW + me->name() + "真气运转一周天，深深吸了一口气，精神看起来好多了。\n" NOR,
           environment(me), me);

    me->receive_curing("jing", 10 + (int)me->query_skill("force")/5 );
    me->add("neili", -50);
    me->add("jingli", -50);
    me->set("jiali", 0);
    me->start_busy(1);

    return 1;
}
