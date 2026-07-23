// lifeheal.c for xixin-dafa

#include <ansi.h>

int exert(object me, object target)
{
        if( !target )
                return notify_fail("你要用真气为谁疗伤？\n");

        if( (int)me->query("max_neili") < 350 )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("你的真气不够。\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");

        message_vision(
                HIY "$N运用吸心大法，缓缓地将自己的真气输入$n体内....\n\n"
                "过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来好多了。\n" NOR,
                me, target );
       target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
        target->add("qi", 10 + (int)me->query_skill("force")/3 );
        if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

        me->add("neili", -150);
        me->set("jiali", 0);

        return 1;
}
