// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
    if( !target )
        return notify_fail("你要用真气为谁疗伤？\n");

    if( me->is_fighting() || target->is_fighting())
        return notify_fail("战斗中无法运功疗伤！\n");
    if ((int)me->query_skill("cangming-gong", 1) < 50)
        return notify_fail("你的浩气苍冥功修为还不够，不能为别人疗伤。\n");
    if( (int)me->query("max_neili") < 300 )
        return notify_fail("你的内力修为不够。\n");

    if( (int)me->query("neili") < 150 )
        return notify_fail("你的真气不够。\n");

    if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
        return notify_fail( target->name() +
                "已经受伤过重，经受不起你的真气震荡！\n");
        
    me->start_busy(2);
    if( target != me )
    {
        message_vision( HIY "$N一声长啸，以极快的手法拍在$n胸口，一股大气苍茫的内劲缓缓灌入$n体内....\n"
        "过了不久，$N的汗珠消褪，锁眉逐渐舒缓，$n借$N浩气苍冥功两条青龙疏通了全身经脉气血，大有说不出的畅快。\n" NOR,
        me, target );
    }
    else
    {
        write( HIY "你缓缓坐下，丹田陡然升起两股龙游的真气冲向全身经脉。\n" NOR);
        message("vision", HIY + me->name() + "长长吐出一口黑气，伤势渐复。\n" NOR,
        environment(me), me);
    }
    target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
    target->add("qi", 30 + (int)me->query_skill("force")/3 );
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

    me->add("neili", -150);
    me->set("jiali", 0);

    return 1;
}
