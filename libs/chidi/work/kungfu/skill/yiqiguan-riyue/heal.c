// heal.c

#include <ansi.h>

int exert(object me, object target)
{
           int damage,time;
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if ((int)me->query_skill("yiqiguan-riyue", 1) < 15)
                return notify_fail("你的一气贯日月修为还不够。\n");
        if( (int)me->query("neili") < 50  || (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if( (int)me->query("eff_qi")>=(int)me->query("max_qi"))
               return notify_fail("你没有受伤。\n");
        if (me->query("yiqiguan-riyue")==1) {
        write( HIG "你运起“从心所欲”神功，脸上一会青，一会白。\n" NOR);
        damage=10 + (int)me->query_skill("force")/4;
        time=3;
        }
        if (me->query("yiqiguan-riyue")==2) {
        write( WHT "你运起“登峰造极”神功，全身腾起一团白雾。\n" NOR);
        damage=10 + (int)me->query_skill("force")/3;
        time=2;
        }
        if (!(me->query("yiqiguan-riyue"))) {
        write( YEL "你全身放松，坐下来开始运功疗伤。\n" NOR);
        damage=10 + (int)me->query_skill("force")/5;
        time=4;
        }

        message("vision",
                HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);
        me->receive_curing("qi",damage);
        me->add("neili", -50);
        me->set("jiali", 0);
      me->start_busy(time);

        return 1;
}


