//tangmen-xinfa.heal.c

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("战斗中运功疗伤？找死吗？\n");

    if ((int)me->query_skill("tangmen-xinfa", 1) < 50)
   return notify_fail("你的唐门心法修为还不够。\n");
    if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50)
   return notify_fail("你的真气不够。\n");

    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
   return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
   
    if( (int)me->query("max_qi") < (int)me->query("eff_qi") + 5 )
   return notify_fail("你现在不需要疗伤。\n");  

    write( "你全身放松，坐下来开始运功疗伤。只见你头上盘着一股"+HIG"氤氲之气。\n"NOR);
    message("vision",
    "只见"+me->name() +"头上盘着一股"+HIG"氤氲之气。"NOR+ "突然「哇」吐出一口"+HIR"瘀血"NOR+"，脸色看起来好多了。\n" ,
   environment(me), me);

    me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
    me->add("neili", -50);
    me->set("jiali", 0);

    return 1;
}

