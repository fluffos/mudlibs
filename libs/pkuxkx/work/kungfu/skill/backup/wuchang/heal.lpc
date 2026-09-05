#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
      
        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("exert",
                HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);

        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->add("neili", 500);
      
        return 1;
}
int exert(object me, object target)
{

      
        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("exert",
                HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);

        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->add("neili", 500);
      
        return 1;
}
