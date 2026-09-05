#include <ansi.h>

int exert(object me, object target)
{

        if ((int)me->query_skill("chuforce", 1) < 50)
          return notify_fail("你的楚氏内功修为还不够。\n");
        if( (int)me->query("neili") < 100 ) 
          return notify_fail("你的真气不够。\n");
        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
          return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");


        write( HIW "你暗运真气,运功疗伤。\n" NOR);
        message("exert",
                HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);
        me->receive_curing("qi", 90 + (int)me->query_skill("force")/4 );

        me->add("neili", -90);
      
        return 1;
}
