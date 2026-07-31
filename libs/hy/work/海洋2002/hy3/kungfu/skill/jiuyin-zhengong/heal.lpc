// heal.c

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("战斗中运功疗伤？找死吗？\n");

    if ((int)me->query_skill("jiuyin-zhengong", 1) < 20)
   return notify_fail("你的九阴真功修为还不够。\n");
    if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50)
   return notify_fail("你的真气不够。\n");

    if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
   return notify_fail("你并未受伤！\n");
   
    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
   return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

    write( HIB "你全身放松，按照九阴锻筋篇开始运功疗伤。\n" NOR);
    message("vision",
   HIB + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
   environment(me), me);

    me->receive_curing("qi", 10 + (int)me->query_skill("force")/4 );
    me->add("neili", -50);

    return 1;
}

